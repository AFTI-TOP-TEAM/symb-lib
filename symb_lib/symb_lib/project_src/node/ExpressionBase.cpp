#include "ExpressionBase.h"

namespace symb
{
//------------------------------------------------------------------------------	
bool ExpressionBase::IsOptimized() const
{
	return m_optimized;
}
//------------------------------------------------------------------------------
void ExpressionBase::SetOptimized(bool optimized)
{
	m_optimized = optimized;
}
//------------------------------------------------------------------------------
}
