#ifndef mitkIContextMenuAction_H_
#define mitkIContextMenuAction_H_

#include <vector>
#include <mitkDataNode.h>
#include <berryMacros.h>
#include "mitkDataStorage.h"

namespace berry
{
  class QtViewPart;
}

namespace mitk
{
  /**
  * A context menu action, which is linked to the context menu <br>
  * through an extension point. For an example check the <br>
  * <code> plugin.xml </code> and the connected classes of <br>
  * the the segmentation bundle and also the <code> QmitkDataManagerView.cpp </code> <br>
  * in this bundle.
  */
  struct IContextMenuAction
  {   
    berryInterfaceMacro(IContextMenuAction, mitk)

      /**
      * @brief Executes the action, that linked to the context menu entry.
      */
      virtual void Run( const std::vector<mitk::DataNode*>& selectedNodes ) = 0;

    // Setters
    virtual void SetDataStorage(mitk::DataStorage* dataStorage) = 0;
    virtual void SetSmoothed(bool smoothed) = 0;
    virtual void SetFunctionality(berry::QtViewPart* functionality) = 0;
  };
}

#endif // mitkIContextMenuAction_H_ 