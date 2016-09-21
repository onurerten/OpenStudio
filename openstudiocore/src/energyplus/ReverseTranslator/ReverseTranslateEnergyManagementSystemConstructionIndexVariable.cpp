/**********************************************************************
 *  Copyright (c) 2008-2016, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#include "../ReverseTranslator.hpp"

#include "../../model/EnergyManagementSystemConstructionIndexVariable.hpp"
#include "../../model/EnergyManagementSystemConstructionIndexVariable_Impl.hpp"

#include <utilities/idd/EnergyManagementSystem_ConstructionIndexVariable_FieldEnums.hxx>
#include "../../utilities/idd/IddEnums.hpp"
#include <utilities/idd/IddEnums.hxx>

using namespace openstudio::model;

namespace openstudio {

namespace energyplus {

OptionalModelObject ReverseTranslator::translateEnergyManagementSystemConstructionIndexVariable(const WorkspaceObject & workspaceObject)
{
  if (workspaceObject.iddObject().type() != IddObjectType::EnergyManagementSystem_ConstructionIndexVariable) {
    LOG(Error, "WorkspaceObject is not IddObjectType: EnergyManagementSystem_ConstructionIndexVariable");
    return boost::none;
  }

  OptionalString s = workspaceObject.getString(EnergyManagementSystem_ConstructionIndexVariableFields::Name);
  if(!s){
    return boost::none;
  }

  s = workspaceObject.getString(EnergyManagementSystem_ConstructionIndexVariableFields::ConstructionObjectName);
  if (!s) {
    return boost::none;
  }

  Workspace workspace = workspaceObject.workspace();

  if (s) {
    for ( WorkspaceObject& wsObject : workspace.getObjectsByName(*s)) {
      boost::optional<model::ModelObject> modelObject = translateAndMapWorkspaceObject(wsObject);
      if (modelObject) {
        openstudio::model::EnergyManagementSystemConstructionIndexVariable emsConstructionIndexVariable(m_model);
        OptionalString s1 = workspaceObject.getString(EnergyManagementSystem_ConstructionIndexVariableFields::Name);
        emsConstructionIndexVariable.setName(*s1);
        emsConstructionIndexVariable.setConstructionObject(modelObject.get());
        return emsConstructionIndexVariable;
      }
    }
  }
  return boost::none;
}

} // energyplus

} // openstudio
