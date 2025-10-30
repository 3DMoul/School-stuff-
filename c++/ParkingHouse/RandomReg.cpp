//#include <string>
//#include <random>
//
//
//using namespace std;
//string generateRandomString(int length)
//{
//    // Define the list of possible characters
//    const string CHARACTERS
//        = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuv"
//        "wxyz0123456789";
//
//    // Create a random number generator
//    random_device rd;
//    mt19937 generator(rd());
//
//    // Create a distribution to uniformly select from all
//    // characters
//    uniform_int_distribution<> distribution(
//        0, CHARACTERS.size() - 1);
//
//    // Generate the random string
//    string random_string;
//    for (int i = 0; i < length; ++i) {
//        random_string
//            += CHARACTERS[distribution(generator)];
//    }
//
//    return random_string;
//}
