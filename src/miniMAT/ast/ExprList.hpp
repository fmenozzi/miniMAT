#ifndef MINIMAT_AST_EXPRLIST_HPP
#define MINIMAT_AST_EXPRLIST_HPP

#include <vector>
#include <memory>

#include <miniMAT/ast/Expression.hpp>

namespace miniMAT {
	namespace ast {
		typedef std::vector<std::shared_ptr<Expression>> ExprList;
	}
}

#endif