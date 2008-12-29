/* rsspp - Copyright (C) 2008 Andreas Krennmair <ak@newsbeuter.org>
 * Licensed under the MIT/X Consortium License. See file LICENSE
 * for more information.
 */

#ifndef RSSPP_INTERNAL__H
#define RSSPP_INTERNAL__H

#include <rsspp.h>

#define CONTENT_URI "http://purl.org/rss/1.0/modules/content/"

namespace rsspp {

struct rss_parser {
		virtual void parse_feed(feed& f, xmlNode * rootNode) = 0;
		virtual ~rss_parser() { }
	protected:
		std::string get_content(xmlNode * node);
};

struct rss_09x_parser : public rss_parser {
	virtual void parse_feed(feed& f, xmlNode * rootNode);
	item parse_item(xmlNode * itemNode);
};

struct rss_10_parser : public rss_parser {
	virtual void parse_feed(feed& f, xmlNode * rootNode);
};

struct rss_20_parser : public rss_09x_parser {
};

struct atom_parser : public rss_parser {
	virtual void parse_feed(feed& f, xmlNode * rootNode);
};

struct rss_parser_factory {
	static rss_parser * get_object(feed& f);
};

}

#endif
