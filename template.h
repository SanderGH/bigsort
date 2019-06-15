#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*template <class T, template <class> class Container>
ostream& operator<<(ostream& out, Container<T>& vec)
{
	for (const auto& i : vec)
		out << " " << i;
	out << endl;

	return out;
}*/

template <class T>
ostream& operator<<(ostream& out, vector<T>& vec)
{
	for (const auto& i : vec)
		out << " " << i;
	out << endl;

	return out;
}