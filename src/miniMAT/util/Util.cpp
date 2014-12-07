#include <Util.hpp>

#include <iostream>
#include <iomanip>
#include <cstdlib>

namespace miniMAT {
    namespace util {

        // auto doesn't seem to work here, for some reason
        std::map<std::string, std::function<void(void)>> Util::funcs = std::map<std::string, std::function<void(void)>>();

        void Util::init(std::shared_ptr<std::map<std::string, Matrix>> vars) {
            funcs["quit"] = funcs["exit"] = funcs["bye!"] = []() {
                throw 1;
            };

            funcs["who"] = [vars]() {
            	for (auto var : *vars)
                    std::cout << var.first << std::endl;
                std::cout  << std::endl;
            };

            funcs["whos"] = [vars]() {
                using namespace std;

                auto max_width = max_element(begin(*vars), 
                                             end(*vars), 
                                             [](pair<string, Matrix> p1, pair<string, Matrix> p2) {
                    // Compare by variable name length
                    return p1.first.size() < p2.first.size();
                })->first.size();

                cout << endl;
                for (auto var : *vars)
                    cout << setw(max_width) << var.first << " = " << var.second << endl;
                cout << endl;
            };

            funcs[""] = []() {
                return;
            };
        }

        void Util::PrintResult(std::string varname, Matrix m, bool suppressed) {
            if (!suppressed) {
                // Print a row at a time
                std::cout << varname << " =" << std::endl << std::endl;
                for (int i = 0; i < m.rows(); i++)
                    std::cout << "    " << m.block(i, 0, 1, m.cols()) << std::endl;
            }
        }

        std::function<void(void)> Util::GetFunction(const std::string& s) {
        	return funcs[s];
        }

        bool Util::HasFunction(const std::string& s) {
            return funcs.find(s) != funcs.end();
        }
    }
}