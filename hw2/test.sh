#!/bin/bash

./parser <$1 >out
golden_parser <$1 >out2
diff out out2
