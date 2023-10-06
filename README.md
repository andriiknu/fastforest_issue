# Issue with FastForest inference
This repo presents the problem of mismatching `fastforest` inference made on a single input vector in comparison to `xgboost` inference performed on the same input.

* `model.json` is the xgboost model
* `model.txt` is dumped model from `model.json` (using `_Booster.dump_model`)
* `main.py` uses `model.json` to perform inference with `xgboost` in single input
* `main.cpp` uses `model.txt` to perform inference with `fastforest` on the same input

### To reproduce the problem:
#### 1. Compile main.cpp and execute

1. To compile `main.cpp`, is required 
* to have [FastForest lib](https://github.com/guitargeek/XGBoost-FastForest) installed. (See [installation instructions](https://github.com/guitargeek/XGBoost-FastForest#installation)).
* to point out for the C++ compiler where the headers and libs of FastForest are.

I used CMake tool for compilation (see `CMakeLists.txt`):
```bash
mkdir build && cd build
cmake .. && make
```
2. Run executable:
```bash
cd ..
./build/fastforest.exe
```
3. Output:  
```
score =  0.0637436
```
#### 2. Execute `main.py`
* Required packages are listed in `requirements.txt`
* Run `main.py`:
```
python3 main.py
```
Output: 
```
score = 0.7098045945167542
``````

### Possible reasons for the discrepancy
We tested both models on a larger amount of data, and only a small portion of that has given different results. So, this score mismatching is likely **NOT** due:
* wrong conversion from `JSON` to `txt`
* wrong `fastforest` model initialization
