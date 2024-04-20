//includes
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <random>

std::vector<std::string> adj, adv, verb, noun, internet;
std::string seperator;

//readfrom files [tick]
std::vector<std::string> read_words(const std::string& file_name, std::vector<std::string>& words) {
    std::ifstream file(file_name);

    if(file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {
            std::string word;
            std::istringstream iss(line);
            iss >> word;
            words.push_back(word);
        }
        file.close();
    } else {
        std::cerr << "Error opening file: " << file_name << std::endl;
    }

    return words;
}

//actually read and save
void init_reader() {
    read_words("./wordlists/dict/index.adj", adj);
    read_words("./wordlists/dict/index.adv", adv);
    read_words("./wordlists/dict/index.verb", verb);
    read_words("./wordlists/dict/index.noun", noun);
//    read_words("internet.txt", internet);
}

//choose randoms
std::string choose_random_word(std::vector<std::string>& words) {
    if(words.empty()) {
        return " [error] ";
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<size_t> dist(0, words.size() - 1);
    size_t random_index = dist(gen);

    return words[random_index];
}

//actually choose random based on user request
void adj_noun() {
    std::string final_adj = choose_random_word(adj);
    std::string final_noun = choose_random_word(noun);

    std::cout << final_adj << seperator << final_noun << std::endl;
}

void noun_noun() {
    std::string final_noun_1 = choose_random_word(noun);
    std::string final_noun_2 = choose_random_word(noun);

    std::cout << final_noun_1 << seperator << final_noun_2 << std::endl;
}

void verb_noun() {
    std::string final_verb = choose_random_word(verb);
    std::string final_noun = choose_random_word(noun);

    std::cout << final_verb << seperator << final_noun << std::endl;
}

void adv_verb_noun() {
    std::string final_adv = choose_random_word(adv);
    std::string final_verb = choose_random_word(verb);
    std::string final_noun = choose_random_word(noun);

    std::cout << final_adv << seperator << final_verb << seperator << final_noun << std::endl;
}

void special() {}

//main body
int main()
{
    int choice; //user choice for name structure
    int get_choice;
    //seperator defined globally
    int get_seperator;

    std::cout << "choose a structure for your username (default: 1)" << std::endl;
    std::cout << "1. adj + noun" << std::endl;
    std::cout << "2. noun + noun" << std::endl;
    std::cout << "3. verb + noun" << std::endl;
    std::cout << "4. adv + verb + noun" << std::endl;
    std::cout << "5. special (internetized)" << std::endl;
    std::cout << "your choice: ";
    std::cin >> get_choice;

    switch(get_choice) {
        case 1:
            choice = 1;
            break;
        case 2:
            choice = 2;
            break;
        case 3:
            choice = 3;
            break;
        case 4:
            choice = 4;
            break;
        case 5:
            choice = 5;
            break;
        default:
            std::cout << "choosing default option..." << std::endl;
            choice = 1;
    }
    
    std::cout << std::endl << "choose a seperator (default: 1)" << std::endl;
    std::cout << "1. _" << std::endl;
    std::cout << "2. -" << std::endl;
    std::cout << "3. X" << std::endl;
    std::cout << "4. blank (no seperator)" << std::endl;
    std::cout << "your choice: ";
    std::cin >> get_seperator;
    
    switch(get_seperator) {
        case 1:
            seperator = "_";
            break;
        case 2:
            seperator = "-";
            break;
        case 3:
            seperator = "X";
            break;
        case 4:
            seperator = "";
            break;
        default:
            std::cout << "choosing default option..." << std::endl;
            seperator = "_";
    }

    if (choice >= 1 && choice <= 5) {
        init_reader();
    }

    std::cout << std::endl << "here are your random usernames: " << std::endl;

    if (choice == 1) {
        for (size_t i {0}; i < 5; ++i) {
            adj_noun();
        }
    } else if (choice == 2) {
        for (size_t i {0}; i < 5; ++i) {
            noun_noun();
        }    
    } else if (choice == 3) {
        for (size_t i {0}; i < 5; ++i) {
            verb_noun();
        }
    } else if (choice == 4) {
        for (size_t i {0}; i < 5; ++i) {
            adv_verb_noun();
        }
    } else if (choice == 5) {
        for (size_t i {0}; i < 5; ++i) {
            special();
        }
    } else {
        std::cout << "oops! there was an error :( " << std::endl;
    }

    return 0;
}
