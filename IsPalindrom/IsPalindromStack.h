#pragma once

#include <string>
#include <stack>

bool isPalindromeStack(const std::string& str) {
	std::stack<char> s;
	for (char ch : str) {
		s.push(ch);
	}
	for (char ch : str) {
		if (ch != s.top()) {
			return false;
		}
		s.pop();
	}
	return true;
}
