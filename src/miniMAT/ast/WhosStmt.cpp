#include <miniMAT/ast/WhosStmt.hpp>

#include <miniMAT/util/PrintResult.hpp>

#include <iostream>
#include <iomanip>

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

                auto max_width = max_element(vars->begin(), 
                                             vars->end(), 
                                             [](pair<string, Matrix> p1, pair<string, Matrix> p2) {
                    // Compare by variable name length
                    return p1.first.size() < p2.first.size();
                })->first.size();

                cout << endl;
                for (auto var : *vars) {
                    cout << setw(max_width);
                    util::PrintResult(var.first, var.second, false);
                }
            }

        	return Matrix::Zero(0,0);
        }

        void WhosStmt::VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                  std::shared_ptr<reporter::ErrorReporter> reporter) const {
     
        }
	}
}