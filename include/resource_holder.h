/*
 * resource_holder.h
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#ifndef RESOURCE_HOLDER_H
#define RESOURCE_HOLDER_H


#include <string>
#include <map>
#include <memory>
#include <stdexcept>


template <typename Resource, typename Identifier>
class ResourceHolder
{
	public:
		void load(Identifier id, const std::string& filename);
		Resource& get(Identifier id);
		const Resource& get(Identifier id) const;

	private:
		std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#endif /* RESOURCE_HOLDER_H */ 
