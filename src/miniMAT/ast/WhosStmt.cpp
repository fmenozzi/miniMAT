#include <miniMAT/ast/WhosStmt.hpp>

#include <miniMAT/util/PrintResult.hpp>

#include <iostream>
#include <iomanip>

#include <cstring>

namespace miniMAT {
    namespace ast {
        std::string WhosStmt::GetClassName() const {
            return "WhosStmt";
        }

        void WhosStmt::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
        }

        Matrix WhosStmt::VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) {
            if (vars->size() != 0) {
                using namespace std;

                // Get max variable name length
                auto maxwidth = max_element(vars->begin(), vars->end(), [](pair<string, Matrix> p1, pair<string, Matrix> p2) {
                    return p1.first.size() < p2.first.size();}
                )->first.size();

                // Get number of digits in "largest" row and col dimensions
                auto rowcompare = [](pair<string, Matrix> p1, pair<string, Matrix> p2) {
                    int firstlength  = log10(p1.second.rows()) + 1;
                    int secondlength = log10(p2.second.rows()) + 1;
                    return firstlength < secondlength;
                };
                auto colcompare = [](pair<string, Matrix> p1, pair<string, Matrix> p2) {
                    int firstlength  = log10(p1.second.cols()) + 1;
                    int secondlength = log10(p2.second.cols()) + 1;
                    return firstlength < secondlength;
                };
                int maxrows = log10(max_element(vars->begin(), vars->end(), rowcompare)->second.rows()) + 1;
                int maxcols = log10(max_element(vars->begin(), vars->end(), colcompare)->second.cols()) + 1;

                // Get number of digits in largest size (in bytes)
                int doublesize  = sizeof(double);
                auto sumcompare = [](pair<string, Matrix> p1, pair<string, Matrix> p2) {
                    return p1.second.sum() < p2.second.sum();
                };
                int maxbytes = log10(max_element(vars->begin(), vars->end(), sumcompare)->second.sum() * doublesize) + 1;

                int space = 6;

                int totalbytes = 0;
                int totalsize  = 0;

                int namewidth = maxwidth + space;
                int sizewidth = maxrows+1+maxcols + space;
                int bytewidth = maxbytes + space;

                cout << setw(namewidth) << right << "Name" << setw(sizewidth) << right << "Size" << setw(bytewidth) << right << "Bytes" << endl;
                cout << setw(namewidth) << right << "====" << setw(sizewidth) << right << "====" << setw(bytewidth) << right << "=====" << endl;
                for (auto var : *vars) {
                    auto varname = var.first;

                    auto rowstr  = to_string(var.second.rows());
                    auto colstr  = to_string(var.second.cols());

                    auto bytes   = static_cast<int>(var.second.size() * doublesize);
                    auto bytestr = to_string(bytes);

                    totalbytes += bytes;
                    totalsize  += 1;

                    cout << setw(namewidth) << right << varname << setw(maxrows+space) << right << rowstr << "x" << setw(maxcols+space) << left << colstr << setw(maxbytes) << right << bytestr << endl;
                }
                cout << endl << "Grand total is " << totalsize << " elements using " << totalbytes << " bytes" << endl;
            }

            return Matrix::Zero(0,0);
        }

        void WhosStmt::VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                  std::shared_ptr<reporter::ErrorReporter> reporter) const {
     
        }
    }
}