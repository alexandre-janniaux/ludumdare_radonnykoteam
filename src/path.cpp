#include "path.hpp"

Path::Path()
: mPath()
{
}

void Path:addBranch(Node::ID node, Branch::ID branch, float len)
{
    mPath.push_back((node, branch));
	m_length += d;
}


Branch::ID Path::getBranchID(int n) {
  return mPath[n].second();
}

/*float Path::length()
{
    float length = 0.f;
    for (auto pere : mPath)
    {
        Branch::ID branch = pere.sd;
        length += branch.getLength();
    }
    return length;
}*/
