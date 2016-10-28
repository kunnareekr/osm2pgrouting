/***************************************************************************
 *   Copyright (C) 2016 by pgRouting developers                            *
 *   project@pgrouting.org                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License t &or more details.                        *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef SRC_CLASS_H_
#define SRC_CLASS_H_

#include <boost/lexical_cast.hpp>
#include <osm_elements/osm_element.h>
#include <cassert>
#include <map>
#include <string>
#include <vector>

namespace osm2pgr {

class Tag_value : public Element {
 public:
     Tag_value() = default;
     Tag_value(const Tag_value &) = default;
     explicit Tag_value(const char ** attributes);


     inline int64_t id() const {return osm_id();}

     std::vector<std::string> export_values() const; 

     inline std::string name() const {
         assert(has_attribute("name"));
         return has_attribute("name") ?
             get_attribute("name")
             : "";
     }
     inline double priority() const {
#if 0
         assert(has_attribute("priority)"));
#endif
         return  has_attribute("priority") ?
             boost::lexical_cast<double>(get_attribute("priority"))
             : 1;
     }
     inline double default_maxspeed() const {
         return (has_attribute("maxspeed")) ? 
           boost::lexical_cast<double>(get_attribute("maxspeed"))
           : 50;
     }
 private:

};


}  // end namespace osm2pgr
#endif  // SRC_CLASS_H_
