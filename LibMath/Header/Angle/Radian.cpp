#include "Radian.h"

LibMath::Radian::Radian()
{
    m_value = 0;
}

LibMath::Radian::Radian(float value)
{
    m_value = value;
}

LibMath::Radian::Radian(Radian const& radian)
{
    m_value = radian.m_value;
}

LibMath::Radian::~Radian()
{

}

float LibMath::Radian::raw() const
{
    return m_value;
}

