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

MLKIT_NAMESPACE_DEFINE
MLKIT_DATA_NAMESPACE_DEFINE

class label_vector
{

private:

  std::string __label;
  std::vector<mlkit::data::cell> __cells;

public:

  label_vector(const std::string &label)
  {

    __label = label;
    __cells = std::vector<mlkit::data::cell>();

  }

  std::string label() const { return __label; }
  std::vector<mlkit::data::cell>& cells() { return __cells; }

};

MLKIT_NAMESPACE_CLOSE
MLKIT_DATA_NAMESPACE_CLOSE

#endif //MLKIT_LABEL_VECTOR_H
