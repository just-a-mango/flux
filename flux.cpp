#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <fstream>
#include <vector>
#include <cctype>
#include <functional>
#include <regex>
#include <sstream>
#include <chrono>
using namespace std;

vector<tuple<string,string>> vars;
vector<tuple<string,string,vector<string>>> funcs;
vector<tuple<int,vector<string>>> lists;
int curren_line = 0;



/**
 * It prints out an error message and exits the program
 * 
 * @param message The error message to be displayed.
 */
void error(string message) {
    std::cout << "        \033[1m\033[91m   Flux Error  \033[0m        " << std::endl << "At \033[1m\033[92mline " << curren_line << "\033[0m" << std::endl << "\033[1m" << message << "\033[0m" << std::endl;
    exit(EXIT_FAILURE);
}


/**
 * Print() takes a string as an argument and prints it to the console.
 * 
 * @param to_print The string to print.
 * 
 * @return Nothing.
 */
void print(string to_print) {
    cout << to_print << endl;
    return;
}


/**
 * It takes a string, and returns a copy of the string with all leading and trailing whitespace filtered
 * 
 * @param input The string to be stripped.
 * 
 * @return A string.
 */
string strip(const string &input)
{
    auto start_it = input.begin();
    auto end_it = input.rbegin();
    while (std::isspace(*start_it))
        ++start_it;
    while (std::isspace(*end_it))
        ++end_it;
    return string(start_it, end_it.base());
}


/**
 * It takes a string, searches for a substring within it, and replaces that substring with another
 * substring
 * 
 * @param subject The string to search and replace in.
 * @param search The string to search for.
 * @param replace The string to search for.
 * 
 * @return the string subject.
 */
string replace(string subject, const string& search,
                          const string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
    return subject;
}


/**
 * It replaces the first occurrence of a string with another string
 * 
 * @param s The string to search in
 * @param toReplace The string to replace
 * @param replaceWith The string to replace toReplace with.
 */
void replaceFirst(string& s, const string& toReplace, const string& replaceWith)
{
    size_t pos = s.find(toReplace);
    if(pos != string::npos)
    {
        s.replace(pos, toReplace.length(), replaceWith);
    }
}


/**
 * It finds the last occurrence of the string toReplace in the string str and replaces it with the
 * string replaceWith
 * 
 * @param str The string in which we want to replace the last occurrence of toReplace with replaceWith.
 * @param toReplace The string to be replaced
 * @param replaceWith The string that will replace the last occurrence of toReplace in str.
 */
void replaceLast(string &str, const string &toReplace, const string &replaceWith) 
{ 
    // Find last occurence of toReplace in str 
    size_t pos = str.rfind(toReplace); 
  
    // If toReplace is found in str 
    if (pos != string::npos) 
    { 
        // Replace last occurence of toReplace in str 
        // with replaceWith 
        str.replace(pos, toReplace.size(), replaceWith); 
    } 
}


/**
 * It takes a string and a delimiter, and returns a vector of strings
 * 
 * @param str The string to split.
 * @param delimiter The character that separates the tokens in the string.
 * 
 * @return A vector of strings.
 */
vector<string> split_string(const string &str, char delimiter) {
    vector<string> result;
    istringstream iss(str);

    for (string token; getline(iss, token, delimiter);)
        result.push_back(token);

    return result;
}


/**
 * It takes a string and a property, and returns the string with the property applied to it
 * 
 * @param obj The object to process
 * @param property The property to be processed.
 * 
 * @return The return value is the string that is being processed.
 */
string process_property(string obj, string property) {
    if (property == "uppercase") {
        for (auto & c: obj) c = (char)toupper(c);
        return obj;
    } else if (property == "lowercase") {
        transform(obj.begin(), obj.end(), obj.begin(), ::tolower);
        return obj;
    } else if (property == "isnumbers") {
        if (all_of(obj.begin(), obj.end(), ::isdigit)) {
            return "true";
        } else {
            return "false";
        }
    } else if (property == "isletters") {
        if (regex_match(obj, regex("^[A-Za-z]+$"))) {
            return "true";
        } else {
            return "false";
        }
    } else if (property == "capitalize") {
        obj[0] = toupper(obj[0]);
        return obj;
    } else if (property == "isuppercase") {
        if (regex_match(obj, regex("^[A-Z]+$"))) {
            return "true";
        } else {
            return "false";
        }
    } else if (property == "islowercase") {
        if (regex_match(obj, regex("^[a-z]+$"))) {
            return "true";
        } else {
            return "false";
        }
    } else if (property == "strip") {
        return strip(obj);
    } else if (property == "title") {
        for (unsigned int x = 0; x < obj.length(); x++)
	    {
            if (x == 0)
            {
                obj[x] = toupper(obj[x]);
            }
            else if (obj[x - 1] == ' ')
            {
                obj[x] = toupper(obj[x]);
            }
	    }
        return obj;
    } else if (property.substr(0, 7) == "replace") {
        int first = property.find_first_of('[');
        int middle = property.find_last_of('%');
        string one = strip(property.substr(first + 1, middle - first - 1));
        string two =strip(property.substr(middle + 1, property.find_last_of(']') - middle - 1));
        return replace(obj, one, two);
    } else if (property == "bold") {
        string bold = "\033[1m";
        return bold.append(obj).append("\033[0m");
    } else if (property == "red") {
        string red = "\033[31m";
        return red.append(obj).append("\033[0m");
    } else if (property == "green") {
        string green = "\033[32m";
        return green.append(obj).append("\033[0m");
    } else if (property == "yellow") {
        string yellow = "\033[33m";
        return yellow.append(obj).append("\033[0m");
    } else if (property == "blue") {
        string blue = "\033[34m";
        return blue.append(obj).append("\033[0m");
    } else if (property == "magenta") {
        string magenta = "\033[35m";
        return magenta.append(obj).append("\033[0m");
    } else if (property == "cyan") {
        string cyan = "\033[36m";
        return cyan.append(obj).append("\033[0m");
    } else if (property == "white_bg") {
        string white = "\033[30;47m";
        return white.append(obj).append("\033[0m");
    } else if (property == "green_bg") {
        string green = "\033[30;42m";
        return green.append(obj).append("\033[0m");
    }else if (property == "red_bg") {
        string red = "\033[30;41m";
        return red.append(obj).append("\033[0m");
    } else if (property == "yellow_bg") {
        string yellow = "\033[30;43m";
        return yellow.append(obj).append("\033[0m");
    } else if (property == "blue_bg") {
        string blue = "\033[30;44m";
        return blue.append(obj).append("\033[0m");
    } else if (property == "magenta_bg") {
        string magenta = "\033[30;45m";
        return magenta.append(obj).append("\033[0m");
    } else if (property == "cyan_bg") {
        string cyan = "\033[30;46m";
        return cyan.append(obj).append("\033[0m");
    } else if (property == "white_bg_bold") {
        string white = "\033[30;47;1m";
        return white.append(obj).append("\033[0m");
    } else if (property == "green_bg_bold") {
        string green = "\033[30;42;1m";
        return green.append(obj).append("\033[0m");
    }else if (property == "red_bg_bold") {
        string red = "\033[30;41;1m";
        return red.append(obj).append("\033[0m");
    } else if (property == "yellow_bg_bold") {
        string yellow = "\033[30;43;1m";
        return yellow.append(obj).append("\033[0m");
    } else if (property == "blue_bg_bold") {
        string blue = "\033[30;44;1m";
        return blue.append(obj).append("\033[0m");
    } else if (property == "magenta_bg_bold") {
        string magenta = "\033[30;45;1m";
        return magenta.append(obj).append("\033[0m");
    } else if (property == "cyan_bg_bold") {
        string cyan = "\033[30;46;1m";
        return cyan.append(obj).append("\033[0m");
    } else if (property == "white_bg_bold_underline") {
        string white = "\033[30;47;1;4m";
        return white.append(obj).append("\033[0m");
    } else if (property == "green_bg_bold_underline") {
        string green = "\033[30;42;1;4m";
        return green.append(obj).append("\033[0m");
    }
    else if (property == "green_bg_bold_underline") {
        string green = "\033[30;42;1;4m";
        return green.append(obj).append("\033[0m");
    }
    else if (property == "red_bg_bold_underline") {
        string red = "\033[30;41;1;4m";
        return red.append(obj).append("\033[0m");
    }
    else if (property == "yellow_bg_bold_underline") {
        string yellow = "\033[30;43;1;4m";
        return yellow.append(obj).append("\033[0m");
    }
    else if (property == "blue_bg_bold_underline") {
        string blue = "\033[30;44;1;4m";
        return blue.append(obj).append("\033[0m");
    }
    else if (property == "magenta_bg_bold_underline") {
        string magenta = "\033[30;45;1;4m";
        return magenta.append(obj).append("\033[0m");
    }
    else if (property == "cyan_bg_bold_underline") {
        string cyan = "\033[30;46;1;4m";
        return cyan.append(obj).append("\033[0m");
    }
    else if (property == "white_bg_bold_underline_blink") {
        string white = "\033[30;47;1;4;5m";
        return white.append(obj).append("\033[0m");
    }
    else if (property == "green_bg_bold_underline_blink") {
        string green = "\033[30;42;1;4;5m";
        return green.append(obj).append("\033[0m");
    }
    else if (property == "red_bg_bold_underline_blink") {
        string red = "\033[30;41;1;4;5m";
        return red.append(obj).append("\033[0m");
    }
    else if (property == "yellow_bg_bold_underline_blink") {
        string yellow = "\033[30;43;1;4;5m";
        return yellow.append(obj).append("\033[0m");
    }
    else if (property == "blue_bg_bold_underline_blink") {
        string blue = "\033[30;44;1;4;5m";
        return blue.append(obj).append("\033[0m");
    }
    else if (property == "magenta_bg_bold_underline_blink") {
        string magenta = "\033[30;45;1;4;5m";
        return magenta.append(obj).append("\033[0m");
    }
    else if (property == "cyan_bg_bold_underline_blink") {
        string cyan = "\033[30;46;1;4;5m";
        return cyan.append(obj).append("\033[0m");
    }
    else {
        error(string("Unknown property: ").append(property));
    }
    return obj.append(".").append(property);
}

/**
 * It takes a string and a regular expression and returns the number of times the regular expression
 * matches the string
 * 
 * @param s The string to search in
 * @param re The regular expression to match.
 * 
 * @return The number of matches in the string.
 */
int countMatchInRegex(std::string s, std::string re)
{
    std::regex words_regex(re);
    auto words_begin = std::sregex_iterator(
        s.begin(), s.end(), words_regex);
    auto words_end = std::sregex_iterator();

    return std::distance(words_begin, words_end);
}


string process_funcs(string to_process) {
    return "";
}



string process_in(string to_process) {
    // Use regex to find out any object properties and replace them
    string in_str = to_process;
    if (in_str.find("(") != string::npos) {
        int match_count = countMatchInRegex(in_str, "\\([^ ()]*\\.[^ ()]*\\)");
        for (int i = 0; i < match_count; ++i) {
            regex r("\\([^ ()]*\\.[^ ()]*\\)");
            smatch m;
            regex_search(in_str, m, r);
            string obj = m.str();
            obj = obj.substr(1, obj.length() - 2);
            string property = obj.substr(obj.find(".") + 1);
            obj = obj.substr(0, obj.find("."));
            in_str = replace(in_str, m.str(), process_property(obj, property));
        }
    }
    for (auto i : vars) {
        if (in_str.substr(0, 5) == "(var)") {
            string var_test = in_str;
            size_t pos = 0;
            while ((pos = var_test.find("(var)", pos)) != string::npos) {
                var_test.replace(pos, string("(var)").length(), "");
                pos += string("").length();
            }
            if (var_test == get<0>(i)) {
                in_str = replace(replace(in_str, "(var)",""), get<0>(i), get<1>(i));
            }
            }
    }
    if (in_str.find("+") != string::npos) {
        for (auto i : split_string(in_str, '+')) {
            if (strip(i).substr(0, 5) == "(var)") {
                for (auto j : vars) {
                    if (replace(strip(i), "(var)","") == get<0>(j)) {
                        replaceFirst(in_str, "+","");
                        in_str = replace(in_str, strip(i), get<1>(j));
                    }
                }
            } 
            else {
                replaceFirst(in_str, "+","");
            }
        }
    }
    return in_str;
}


string process_inline(string to_process) {
    if (to_process.find("usr_in(") != string::npos) {
        regex e("usr_in\\([^)]*\\)");
        for (std::sregex_iterator i = std::sregex_iterator(to_process.begin(), to_process.end(), e); i != std::sregex_iterator(); ++i) {                                        
            std::string origin_match = smatch(*i).str();
            string to_cout = strip(replace(origin_match, "usr_in",""));
            replaceFirst(to_cout, "(","");
            replaceLast(to_cout, ")","");
            cout << process_in(to_cout);
            string input;
            getline(cin, input);
            to_process = replace(to_process, origin_match, input);
        }
    }   
    return to_process;
}


/**
 * It takes a string, splits it into tokens, and then processes the tokens
 * 
 * @param line The line of code to process.
 * 
 * @return a string.
 */
void process(string line) {
    // Splitting the string into tokens.
    vector<string> tokens = split_string(line, ' ');
    if (tokens[0] == "var") {
        /* Declaring a variable and assigning it a value. */
        if (__builtin_expect(tokens[2] != "=" || tokens[3] == "",0)) {
            error("Bad syntax when declaring variable");
        }
        string filtered = line;
        replaceFirst(filtered, "var","");
        replaceFirst(filtered, tokens[1], "");
        replaceFirst(filtered, "=", "");
        filtered = process_in(process_inline(strip(filtered)));
        for (tuple<string, string> &i : vars) {
            if (get<0>(i) == tokens[1]) {
                get<1>(i) = filtered;
                return;
            }
        }
        vars.push_back(make_tuple(tokens[1], strip(filtered)));
    }
    else if (tokens[0] == "print") {
        if (__builtin_expect(tokens[1] != "->",0)) {
            error("Bad syntax when declaring variable");
        }
        cout << process_in(process_inline(strip(split_string(line, '->')[1]))) << endl;
    }
    else if (line.substr(0, 6) == "exit()") {
        exit(0);
    }
    else {
        error("Unknown command");
    }
}



/**
 * It takes a string, and if it's not empty, it processes it
 * 
 * @param argc The number of arguments passed to the program
 * @param argv The arguments passed to the program.
 * 
 * @return The return value of the function.
 */
int main(int argc, char** argv) {
  if (argc < 2) {
    return 0;
  }
  auto start = chrono::high_resolution_clock::now();
  ifstream input_file(argv[1]);
  if (__builtin_expect(input_file.good() && string(argv[1]).substr(string(argv[1]).find_last_of(".") + 1) == "flux", 1)) {
    string line;
    while (getline(input_file, line)) {
        curren_line++;
        if (__builtin_expect(line != "", 1)) {
            process(line);
        }
    }
  } else {
    cout << "\033[31mCould not open file\033[0m" << endl;
  }
  auto stop = chrono::high_resolution_clock::now();
  cout << "Execution time:" <<chrono::duration_cast<chrono::microseconds>(stop - start).count()*0.000001 << " seconds" << endl;
  return 0;
}