/**
 * \file PictureFactory.h
 *
 * \author Ethan Clifford
 *
 * A factory class that builds our picture
 */

#pragma once
#include <memory>
#include "Picture.h"

/**
* A factory class that builds our picture.
*/
class CPictureFactory
{
public:
    std::shared_ptr<CPicture> Create();
};

