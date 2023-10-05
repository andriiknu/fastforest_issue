# Issue with FastForest inference
This repo presents the problem of mismatching `fastforest` inference made on a single input vector in comparison to `xgboost` inference performed on the same input.

* `model.json` is the original xgboost model
* `model.txt` is dumped from `model.json` (using `_Booster.dump_model`)
* `main.py` - inference with `xgboost`
* `main.cpp` - inference with `fastforest`
