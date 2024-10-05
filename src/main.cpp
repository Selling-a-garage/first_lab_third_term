#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <filesystem>

#include "../inc/UniformDice.h"
#include "../inc/ThreeDicePool.h"
#include "../inc/PenaltyDice.h"
#include "../inc/BonusDice.h"
#include "../inc/DoubleDice.h"
#include "../inc/DiceFuncs.h"

#define NUMBER_OF_ROLLS_EXP 1000000
#define NUMBER_OF_ROLLS_PROB 100000

#define SEED 15

#define UNIFORM_MAX 99
#define THREE_POOL_MAX 9
#define PROB_MAX 100
#define THREE_PROB_MAX 6

double* ProbAnalysis(AbstractDice* D){
    double* data = new double[std::max(2*PROB_MAX, 3*THREE_PROB_MAX)];
    for(int i=1; i<= std::max(2*PROB_MAX, 3*THREE_PROB_MAX); ++i){
        data[i-1] = value_probability(i, *D, NUMBER_OF_ROLLS_PROB);
    }
    return data;
}

double* ProbAnalysis(DoubleDice* D){
    double* data = new double[std::max(2*PROB_MAX, 3*THREE_PROB_MAX)];
    for(int i=1; i<= std::max(2*PROB_MAX, 3*THREE_PROB_MAX); ++i){
        data[i-1] = value_probability(i, *D, NUMBER_OF_ROLLS_PROB);
    }
    return data;
}

std::string currentDateTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm local_time = *std::localtime(&now_time);
    
    std::ostringstream oss;
    oss << std::put_time(&local_time, "%Y-%m-%d_%H-%M-%S");
    return oss.str();
}

void CSV_writer(){
    UniformDice* UD = new UniformDice(PROB_MAX, SEED);
    BonusDice* BD = new BonusDice(*UD);
    PenaltyDice* PD = new PenaltyDice(*UD);
    ThreeDicePool* TD = new ThreeDicePool(THREE_PROB_MAX, SEED, SEED+1, SEED+2);
    DoubleDice* DD = new DoubleDice(*UD);
    double* UD_data=ProbAnalysis(UD);
    double* PD_data=ProbAnalysis(PD);
    double* TD_data=ProbAnalysis(TD);
    double* BD_data=ProbAnalysis(BD);
    double* DD_data=ProbAnalysis(DD);
    std::string filename = "data/tests/data" + currentDateTime() + ".csv";
    std::cout << filename << std::endl;
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Something wrong with file =(" << std::endl;
    }
    file << "N,UD,PD,BD,TD,DD\n";
    for(int i = 0; i<std::max(2*PROB_MAX, 3*THREE_PROB_MAX); ++i){
        file << i+1 << "," << UD_data[i] << "," << PD_data[i] << "," << BD_data[i] << "," << TD_data[i]<< "," << DD_data[i] <<"\n";
    }
    file.close();
    delete UD_data;
    delete PD_data;
    delete BD_data;
    delete DD_data;
    delete TD_data;
}


double expected_value(AbstractDice* d, unsigned number_of_rolls) {
    unsigned long long accum = 0;
    for (unsigned cnt = 0; cnt < number_of_rolls; ++cnt)
        accum += d->roll();
    return static_cast<double>(accum) / static_cast<double>(number_of_rolls); 
}

int main(){

UniformDice* D1 = new UniformDice(UNIFORM_MAX, SEED);
std::cout<<"Approximate math expectation of UniformDice: "<<expected_value(*D1, NUMBER_OF_ROLLS_EXP)<<std::endl;

ThreeDicePool* D2 = new ThreeDicePool(THREE_POOL_MAX, SEED, SEED, SEED);
std::cout<<"Approximate math expectation of ThreeDicePool: "<<expected_value(*D2, NUMBER_OF_ROLLS_EXP)<<std::endl;

BonusDice* D3 = new BonusDice(*D1);
std::cout<<"Approximate math expectation of BonusDice: "<<expected_value(*D3, NUMBER_OF_ROLLS_EXP)<<std::endl;

PenaltyDice* D4 = new PenaltyDice(*D1);
std::cout<<"Approximate math expectation of PenaltyDice: "<<expected_value(*D4, NUMBER_OF_ROLLS_EXP)<<std::endl;

DoubleDice* D5 = new DoubleDice(*D1);
std::cout<<"Approximate math expectation of DoubleDice: "<<expected_value(*D5, NUMBER_OF_ROLLS_EXP)<<std::endl;

CSV_writer();

}








