#include "fastforest.h"
#include <cmath>
#include <iostream>

fastforest::FastForest get_model (const std::string& path_to_model, size_t nfeatures) {

    std::vector<std::string> feature_names(nfeatures);
    for (int i = 0; i < nfeatures; ++i) {
        feature_names[i] = "f"+std::to_string(i);
    }

    return fastforest::load_txt(path_to_model, feature_names);
}

int main () {
    auto model = get_model("model.txt", 20);
    float input[] = {1.7031662464141846, 1.6687114238739014, 1.5754574537277222, 2.900691509246826, 100.23957824707031, 155.67808532714844, 287.4523620605469, 155.5530548095703, 50.84375, 145.75, 54.15625, 46.09375, 0.1103515625, 0.2412109375, 0.9990234375, 0.7802734375, 0.2880859375, 0.01377105712890625, 0.0240936279296875, 0.12042236328125};
    float score = 1./(1. + std::exp(-model(input, 0.0F)));
    std::cout << "score =  " << score << '\n';
}




