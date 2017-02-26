//
//  main.cpp
//  simple_GA
//
//  Created by András Zalavári on 2017. 02. 26..
//  Copyright © 2017. András Zalavári. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include "Statistics.h"
#define RANDOM_NUM      ((float)rand()/(RAND_MAX))

using namespace std;
string lorem = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit vel, luctus pulvinar, hendrerit id, lorem. Maecenas nec odio et ante tincidunt tempus. Donec vitae sapien ut libero venenatis faucibus. Nullam quis ante. Etiam sit amet orci eget eros faucibus tincidunt. Duis leo. Sed fringilla mauris sit amet nibh. Donec sodales sagittis magna. Sed consequat, leo eget bibendum sodales, augue velit cursus nunc, quis gravida magna mi a libero. Fusce vulputate eleifend sapien. Vestibulum purus quam, scelerisque ut, mollis sed, nonummy id, metus. Nullam accumsan lorem in dui. Cras ultricies mi eu turpis hendrerit fringilla. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; In ac dui quis mi consectetuer lacinia. Nam pretium turpis et arcu. Duis arcu tortor, suscipit eget, imperdiet nec, imperdiet iaculis, ipsum. Sed aliquam ultrices mauris. Integer ante arcu, accumsan a, consectetuer eget, posuere ut, mauris. Praesent adipiscing. Phasellus ullamcorper ipsum rutrum nunc. Nunc nonummy metus. Vestibulum volutpat pretium libero. Cras id dui. Aenean ut eros et nisl sagittis vestibulum. Nullam nulla eros, ultricies sit amet, nonummy id, imperdiet feugiat, pede. Sed lectus. Donec mollis hendrerit risus. Phasellus nec sem in justo pellentesque facilisis. Etiam imperdiet imperdiet orci. Nunc nec neque. Phasellus leo dolor, tempus non, auctor et, hendrerit quis, nisi. Curabitur ligula sapien, tincidunt non, euismod vitae, posuere imperdiet, leo. Maecenas malesuada. Praesent congue erat at massa. Sed cursus turpis vitae tortor. Donec posuere vulputate arcu. Phasellus accumsan cursus velit. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Sed aliquam, nisi quis porttitor congue, elit erat euismod orci, ac placerat dolor lectus quis orci. Phasellus consectetuer vestibulum elit. Aenean tellus metus, bibendum sed, posuere ac, mattis non, nunc. Vestibulum fringilla pede sit amet augue. In turpis. Pellentesque posuere. Praesent turpis. Aenean posuere, tortor sed cursus feugiat, nunc augue blandit nunc, eu sollicitudin urna dolor sagittis lacus. Donec elit libero, sodales nec, volutpat a, suscipit non, turpis. Nullam sagittis. Suspendisse pulvinar, augue ac venenatis condimentum, sem libero volutpat nibh, nec pellentesque velit pede quis nunc. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Fusce id purus. Ut varius tincidunt libero. Phasellus dolor. Maecenas vestibulum mollis diam. Pellentesque ut neque. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. In dui magna, posuere eget, vestibulum et, tempor auctor, justo. In ac felis quis tortor malesuada pretium. Pellentesque auctor neque nec urna. Proin sapien ipsum, porta a, auctor quis, euismod ut, mi. Aenean viverra rhoncus pede. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Ut non enim eleifend felis pretium feugiat. Vivamus quis mi. Phasellus a est. Phasellus magna. In hac habitasse platea dictumst. Curabitur at lacus ac velit ornare lobortis. Curabitur a felis in nunc fringilla tristique. Morbi mattis ullamcorper velit. Phasellus gravida semper nisi. Nullam vel sem. Pellentesque libero tortor, tincidunt et, tincidunt eget, semper nec, quam. Sed hendrerit. Morbi ac felis. Nunc egestas, augue at pellentesque laoreet, felis eros vehicula leo, at malesuada velit leo quis pede. Donec interdum, metus et hendrerit aliquet, dolor diam sagittis ligula, eget egestas libero turpis vel mi. Nunc nulla. Fusce risus nisl, viverra et, tempor et, pretium in, sapien. Donec venenatis vulputate lorem. Morbi nec metus. Phasellus blandit leo ut odio. Maecenas ullamcorper, dui et placerat feugiat, eros pede varius nisi, condimentum viverra felis nunc et lorem. Sed magna purus, fermentum eu, tincidunt eu, varius ut, felis. In auctor lobortis lacus. Quisque libero metus, condimentum nec, tempor a, commodo mollis, magna. Vestibulum ullamcorper mauris at ligula. Fusce fermentum. Nullam cursus lacinia erat. Praesent blandit laoreet nibh. Fusce convallis metus id felis luctus adipiscing. Pellentesque egestas, neque sit amet convallis pulvinar, justo nulla eleifend augue, ac auctor orci leo non est. Quisque id mi. Ut tincidunt tincidunt erat. Etiam feugiat lorem non metus. Vestibulum dapibus nunc ac augue. Curabitur vestibulum aliquam leo. Praesent egestas neque eu enim. In hac habitasse platea dictumst. Fusce a quam. Etiam ut purus mattis mauris sodales aliquam. Curabitur nisi. Quisque malesuada placerat nisl. Nam ipsum risus, rutrum vitae, vestibulum eu, molestie vel, lacus. Sed augue ipsum, egestas nec, vestibulum et, malesuada adipiscing, dui. Vestibulum facilisis, purus nec pulvinar iaculis, ligula mi congue nunc, vitae euismod ligula urna in dolor. Mauris sollicitudin fermentum libero. Praesent nonummy mi in odio. Nunc interdum lacus sit amet orci. Vestibulum rutrum, mi nec elementum vehicula, eros quam gravida nisl, id fringilla neque ante vel mi. Morbi mollis tellus ac sapien. Phasellus volutpat, metus eget egestas mollis, lacus lacus blandit dui, id egestas quam mauris ut lacus. Fusce vel dui. Sed in libero ut nibh placerat accumsan. Proin faucibus arcu quis ante. In consectetuer turpis ut velit. Nulla sit amet est. Praesent metus tellus, elementum eu, semper a, adipiscing nec, purus. Cras risus ipsum, faucibus ut, ullamcorper id, varius ac, leo. Suspendisse feugiat. Suspendisse enim turpis, dictum sed, iaculis a, condimentum nec, nisi. Praesent nec nisl a purus blandit viverra. Praesent ac massa at ligula laoreet iaculis. Nulla neque dolor, sagittis eget, iaculis quis, molestie non, velit. Mauris turpis nunc, blandit et, volutpat molestie, porta ut, ligula. Fusce pharetra convallis urna. Quisque ut nisi. Donec mi odio, faucibus at, scelerisque quis, convallis in, nisi. Suspendisse non nisl sit amet velit hendrerit rutrum. Ut leo. Ut a nisl id ante tempus hendrerit. Proin pretium, leo ac pellentesque mollis, felis nunc ultrices eros, sed gravida augue augue mollis justo. Suspendisse eu ligula. Nulla facilisi. Donec id justo. Praesent porttitor, nulla vitae posuere iaculis, arcu nisl dignissim dolor, a pretium mi sem ut ipsum. Curabitur suscipit suscipit tellus. Praesent vestibulum dapibus nibh. Etiam iaculis nunc ac metus. Ut id nisl quis enim dignissim sagittis. Etiam sollicitudin, ipsum eu pulvinar rutrum, tellus ipsum laoreet sapien, quis venenatis ante odio sit amet eros. Proin magna. Duis vel nibh at";

int POPULATION_SIZE = 80;
int DNA_LENGTH = 13;
string ABC = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ?!.,-";
int ** candidates;

bool compare_cost(pair<int, float>& a, pair<int, float>& b)
{
    return a.second < b.second;
}

void run_simple_evolution(){
    // initalize population
    candidates = new int * [POPULATION_SIZE];
    for (int i=0; i< POPULATION_SIZE; i++){
        candidates[i] = new int [DNA_LENGTH];
        for(int cell_idx=0; cell_idx < DNA_LENGTH; cell_idx++){
            candidates[i][cell_idx] = (int)(RANDOM_NUM * 255);
        }
    }
    cout << "cell " << candidates[0][0] << endl;
    
    int generation = 0;
    bool match = false;
    while (!match) {
        chrono::steady_clock::time_point start = chrono::steady_clock::now();
        // EVALUATE
        // parse phenotypes
        char phenos[POPULATION_SIZE*DNA_LENGTH];
        for (int i=0; i<POPULATION_SIZE; i++){
            for(int cell_idx=0; cell_idx< DNA_LENGTH;cell_idx++){
                int cell = candidates[i][cell_idx];
                phenos[i*DNA_LENGTH+cell_idx] = ABC.at(cell%ABC.length());
            }
        }
        // calculate costs
        vector<pair<int, float>> costs(POPULATION_SIZE);
        //        float costs[POPULATION_SIZE];
        for (int i=0; i<POPULATION_SIZE; i++){
            float difference = 0;
            for(int cell_idx=0; cell_idx < DNA_LENGTH; cell_idx++){
                int diff = (int)phenos[i*DNA_LENGTH+cell_idx] - (int)lorem.at(cell_idx);
                difference += abs(diff);
            }
            pair<int, float> cost;
            cost.first = i;
            cost.second = difference / DNA_LENGTH;
            costs[i] = cost;
            
            if (cost.second == 0)
                match = true;
        }
        
        // EVOLVE
        // select
        vector<int> selection_inidices;
        sort(costs.begin(), costs.end(), compare_cost);
        

        int retain_length = POPULATION_SIZE * 0.2;
        for(int i=0; i<retain_length; i++)
            selection_inidices.push_back(costs[i].first);
        
        for(int i=retain_length; i<POPULATION_SIZE; i++)
            if(RANDOM_NUM<0.05)
                selection_inidices.push_back(costs[i].first);
        
        // breed
        float crossover_rate = 0.7;
        int ** offsprings = new int * [POPULATION_SIZE];
        for (int i=0; i<POPULATION_SIZE; i++) {
            offsprings[i] = new int [DNA_LENGTH];
            if (RANDOM_NUM < crossover_rate){
                int partner_idx = selection_inidices.at(rand() % selection_inidices.size());
                for(int cell_idx=0; cell_idx<DNA_LENGTH; cell_idx++)
                    if(RANDOM_NUM<0.5)
                        offsprings[i][cell_idx] = candidates[partner_idx][cell_idx];
                    else
                        offsprings[i][cell_idx] = candidates[i][cell_idx];
            } else {
                for(int cell_idx=0; cell_idx<DNA_LENGTH; cell_idx++){
                    int cell = candidates[i][cell_idx];
                    offsprings[i][cell_idx] = cell;
                }
            }
        }
        
        // mutate
        float mutation_rate = 0.003;
        for (int i=0; i<POPULATION_SIZE; i++)
            for(int cell_idx=0; cell_idx<DNA_LENGTH; cell_idx++)
                if (RANDOM_NUM<mutation_rate)
                    offsprings[i][cell_idx] = rand()%255;
        
        // DISPLAY
        cout << "Popultation " << generation << endl;
        
        for(int i=0; i<costs.size(); i++){
            int idx = costs[i].first;
            float cost = costs[i].second;
            bool selected = false;
            for (int j=0; j<selection_inidices.size(); j++)
                if(selection_inidices.at(j) == idx)
                    selected = true;
            
            if (selected)
                cout << " * ";
            else
                cout << "   ";
            
            for(int cell_idx = 0; cell_idx<min(DNA_LENGTH, 13); cell_idx++){
                //                cout << ", "<< candidates[idx][cell_idx] << "->";
                cout << (char)phenos[idx*DNA_LENGTH+cell_idx];
            }
            if (DNA_LENGTH>13)
                cout << "...";
            
            cout<< " | " << "#" << setfill('0') << setw(3) << idx << " | " << setprecision(3) << cost << "%";
            cout << endl;
        }
        cout << endl;
        
        // NEXT GENERATION
        for(int i = 0; i < POPULATION_SIZE; ++i) {
            delete [] candidates[i];
        }
        delete[] candidates;
        candidates = offsprings;
        generation++;
        
        // timeit
        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        chrono::milliseconds elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "genaration took " << elapsed.count() << "ms, " <<endl;
    }
}


int main(int argc, const char * argv[]) {
    run_simple_evolution();
    return 0;
}
