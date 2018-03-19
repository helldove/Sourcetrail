#ifndef QT_SEARCH_BAR_H
#define QT_SEARCH_BAR_H

#include <string>

#include <QAbstractItemView>
#include <QFrame>

#include "data/search/SearchMatch.h"

class QtSearchBarButton;
class QtSmartSearchBox;

class QtSearchBar
	: public QFrame
{
	Q_OBJECT

public:
	QtSearchBar();
	virtual ~QtSearchBar();

	virtual QSize sizeHint() const;

	QString query() const;

	void setMatches(const std::vector<SearchMatch>& matches);
	void setFocus();
	void findFulltext();
	void setAutocompletionList(const std::vector<SearchMatch>& autocompletionList);

	QAbstractItemView* getCompleterPopup();

	void refreshStyle();

private slots:
	void homeButtonClicked();

private:
	QWidget* m_searchBoxContainer; // used for correct clipping inside the search box

	QtSmartSearchBox* m_searchBox;

	QtSearchBarButton* m_searchButton;
	QtSearchBarButton* m_homeButton;
};

#endif // QT_SEARCH_BAR_H
