#ifndef ID_REF_HPP
#define ID_REF_HPP

#include <memory>

#include <Reference.hpp>
#include <Identifier.hpp>

namespace miniMAT {
    namespace ast {
        class IdRef : public Reference {
        public:
            IdRef(std::shared_ptr<Identifier> id);
            virtual ~IdRef() {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            double VisitEvaluate(std::shared_ptr<std::map<std::string, double>> id_table) const;
            void VisitCheck(std::shared_ptr<std::map<std::string, double>> id_table,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

        //private:
            std::shared_ptr<Identifier> id;
        };
    }
}

#endif
