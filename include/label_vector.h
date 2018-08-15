//
//  label_vector.h
//  mlkit
//
//  Created by Nidhal DOGGA on 05/08/2018.
//  Copyright © 2018 Nidhal DOGGA. All rights reserved.
//

#ifndef MLKIT_LABEL_VECTOR_H
#define MLKIT_LABEL_VECTOR_H

#include <vector>
#include <string>
#include "macros.h"
#include "cell.h"
#include "vect.h"

MLKIT_NAMESPACE_DEFINE
MLKIT_DATA_NAMESPACE_DEFINE

class label_vector
{

private:

  std::string __label;
  mlkit::data::vect __cells;

public:

  label_vector(const std::string &label)
  {

    __label = label;
    __cells = mlkit::data::vect();

  }

  std::string label() const { return __label; }
  mlkit::data::vect& cells() { return __cells; }

};

MLKIT_NAMESPACE_CLOSE
MLKIT_DATA_NAMESPACE_CLOSE

#endif //MLKIT_LABEL_VECTOR_H
