-- @valton using extensions: ViewPatterns ScopedTypeVariables FlexibleInstances

module Types
  where

import Data.List (stripPrefix)
import Control.Exception (Exception(..))

instance Exception String

data Opts = Opts
  -- !Type to force strict evaulation on field
  { d1 :: !DInt
  , d2 :: !DInt
  , d3 :: !DInt
  , d4 :: !DInt
  , d5 :: !DInt
  , c  :: !Combination
  } deriving (Read, Show, Eq)

data DInt = Dzero | Done | Dtwo | Dthree | Dfour | Dfive | Dsix
  deriving (Eq, Enum, Bounded, Ord)

instance Read DInt where
  readsPrec _ s = check (read s :: Int)
    where check n | n < 0 = []
                  | n > 6 = []
                  | otherwise = [(toEnum n, "")]

instance Show DInt where
  show Dzero  = "0"
  show Done   = "1"
  show Dtwo   = "2"
  show Dthree = "3"
  show Dfour  = "4"
  show Dfive  = "5"
  show Dsix   = "6"

data Combination =
    Pair DInt
  | Three DInt
  | Four DInt
  | Full DInt DInt
  | Straight DInt
  | Yams DInt
    deriving Eq

instance Read Combination where
  {- readsPrec :: Read a => Int -> ReadS a
     notice `a` is inside another type (which happens to be a monad)
     ViewPatterns for the speshul conditions here -}
  readsPrec _ (stripPrefix "pair_"  -> Just a) =
    do n <- reads a
       return (Pair $ fst n, "")

  readsPrec _ (stripPrefix "three_" -> Just a) =
    do n <- reads a
       return (Three $ fst n, "")

  readsPrec _ (stripPrefix "four_"  -> Just a) =
    do n <- reads a
       return (Four $ fst n, "")

  readsPrec _ (stripPrefix "straight_" -> Just a) =
    do n <- reads a
       return (Straight $ fst n, "")

  readsPrec _ (stripPrefix "yams_"  -> Just a) =
    do n <- reads a
       return (Yams $ fst n, "")

  readsPrec _ (stripPrefix "full_"  -> Just (a:'_':b)) =
    do n <- reads (a:"")
       m <- reads b
       return (Full (fst n) (fst m), "")

  readsPrec _ _ = []

instance Show Combination where
  show (Pair a) = show a ++ " pair"
  show (Three a) = show a ++ " three-of-a-kind"
  show (Four a) = show a ++ " four-of-a-kind"
  show (Full a b) = show a ++ " full of " ++ show b
  show (Straight a) = show a ++ " straight"
  show (Yams a) = show a ++ " yams"
