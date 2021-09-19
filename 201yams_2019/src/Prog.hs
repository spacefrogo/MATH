module Prog
  ( parseOpts
  , result
  , except
  ) where

import System.IO (hPutStrLn, stderr)
import System.Exit (exitWith, ExitCode(..))
import Text.Printf (printf)
import Options.Applicative

import Types ( Opts(..)
             , Combination
             )
import Logic (calc)

parseOpts :: ParserInfo Opts
parseOpts = info (helper <*> diceVals) fullDesc
  where
    diceVals :: Parser Opts
    diceVals = Opts
      <$> argument dval (metavar "d1" <> help "value of the first die (0 if not thrown)")
      <*> argument dval (metavar "d2" <> help "value of the second die (0 if not thrown)")
      <*> argument dval (metavar "d3" <> help "value of the third die (0 if not thrown)")
      <*> argument dval (metavar "d4" <> help "value of the fourth die (0 if not thrown)")
      <*> argument dval (metavar "d5" <> help "value of the fifth die (0 if not thrown)")
      <*> argument cval (metavar "c"  <> help "expected combination")
    dval = auto
    cval = auto

result :: Maybe (Combination, Double) -> IO ()
result Nothing = except "Argument error"
result (Just (a, n)) =
  putStrLn ("Chances to get a " ++ (show a) ++ ": "
            ++ (printf "%.2f" $ 100 * n) ++ "%") >> exitWith ExitSuccess

except n = do hPutStrLn stderr n
              exitWith $ ExitFailure 84
