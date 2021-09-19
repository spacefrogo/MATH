module Logic
  ( calc
  ) where

import Data.Function ((&))
import Data.List ( sort
                 , foldl'
                 , foldr
                 )
import Types

{- 1. get list of dice
   2. clean values
   3. get all possible results
   4. find results matching `a` -}
calc :: Opts -> Maybe (Combination, Double)
calc (Opts d1 d2 d3 d4 d5 a) = sort [d1, d2, d3, d4, d5]
                             & prob a

combine :: [DInt] -> [[DInt]]
combine ns = length ns `replicate` ns & sequence
-- combinations, not the same as permutations

prob :: Combination -> [DInt] -> Maybe (Combination, Double)
prob _ [] = Nothing

prob p@(Pair _) (a:[]) = Just (p, 0)
prob p@(Pair a) cs
  | a == Dzero = Nothing
  | otherwise = Just (p, probSame 2 a cs)

prob t@(Three a) cs
  | a == Dzero = Nothing
  | length cs < 3 = Just (t, 0)
  | otherwise = Just (t, probSame 3 a cs)

prob f@(Four a) cs
  | a == Dzero = Nothing
  | length cs < 4 = Just (f, 0)
  | otherwise = Just (f, probSame 4 a cs)

prob f@(Full a b) cs
  | a == Dzero || b == Dzero = Nothing
  | length cs < 5 = Just (f, 0)
  | otherwise = do (_, p) <- prob (Pair a)  cs
                   (_, t) <- prob (Three b) cs
                   return (f, p * t)

prob s@(Straight a) cs
  | a == Dzero = Nothing
  | length cs < 5 = Just (s, 0)
  | last cs < Dfive = Just (s, 0)
  | otherwise = Just (s, 0.0)

prob y@(Yams a) cs
  | a == Dzero = Nothing
  | length cs == 5 = Just (y, probSame 5 a cs)
  | otherwise = Just (y, 0)

probSame :: Int -> DInt -> [DInt] -> Double
probSame i q xs
  | found == 0 = 0
  | found >= i = 1
  | otherwise = foldl' (+) 0 [binomial (5 - found) $ fromIntegral x
                              | x <- pxs]
  where
    found :: Num n => n
    found = fromIntegral . length . filter (==q) $ xs
    pxs = [(i - found)..(6 - found)]

allPossibleDiceRolls :: [[DInt]]
allPossibleDiceRolls = replicate 5 ds & sequence
  where
    ds = [Done, Dtwo, Dthree, Dfour, Dfive, Dsix]

binomial :: Double -> Double -> Double
binomial a b = (factorial a / (factorial b
                             * factorial (a - b))
               ) * ((1 / 6) ** b) * ((5 / 6) ** (a - b))

factorial :: (Ord p, Eq p, Num p, {- can remove when dropping list -} Enum p) => p -> p
factorial n = foldr (*) 1 [1..n]
-- factorial n = product [1..n]
