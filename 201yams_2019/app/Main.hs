module Main where

import Options.Applicative ( execParser )
import Control.Exception ( SomeException
                         , try
                         , handle
                         )
import Prog ( parseOpts
            , except
            , result
            )
import Logic ( calc )
import Types ( Opts )

main :: IO ()
main = handle except $ do
  opts <- try . execParser $ parseOpts :: IO (Either SomeException Opts)
  case opts of
    Left a -> do
      except $ show a
    Right b -> do
      result . calc $ b
