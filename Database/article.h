#ifndef ARTICLE_H__
#define ARTICLE_H__

class Article{
public:
	size_t id;
	string title;
	string contents;
	string writer;
	size_t newsGroup;
	Article(){};
	Article(size_t name, string t): id(name), title(t){};
};
#endif
