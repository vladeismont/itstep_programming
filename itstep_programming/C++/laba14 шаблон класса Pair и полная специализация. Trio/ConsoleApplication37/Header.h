#pragma once

template<typename T>
class Pair {
protected:
	T f, s;
public:
	Pair() {};
	Pair(const T fi, const T se) :f(fi), s(se) {}
	T& first();
	T& second();
	void makePair(const T fi, const T se);
	~Pair() {};
};

template<typename T>
inline T& Pair<T>::first()
{
	// TODO: insert return statement here
	return f;
}

template<typename T>
inline T& Pair<T>::second()
{
	return s;
}

template<typename T>
void Pair<T>::makePair(const T fi, const T se) {
	f = fi;
	s = se;
}

template<>
class Pair<bool> {
	bool f, s;
public:
	Pair() {};
	Pair(const bool fi, const bool se) :f(fi), s(fi) {}
	bool& first();
	bool& second();
	void makePair(const bool fi, const bool se);
	~Pair() {};
};

inline void Pair<bool>::makePair(const bool fi, const bool se)
{
	s = f = fi;
}

inline bool& Pair<bool>::first() {
	return f;
}
inline bool& Pair<bool>::second() {
	return s;
}

template<typename T>
class Trio :public Pair<T> {
	T t;
public:
	Trio() {};
	Trio(T a, T b, T c) :Pair<T>(a, b), t(c) {}
	void makeTrio(const T a, const T b, const T c) { f = a; s = b; t = c; }
	T first() { return f; }
	T second() { return s; }
	T third() { return t; }
	~Trio() {};
};