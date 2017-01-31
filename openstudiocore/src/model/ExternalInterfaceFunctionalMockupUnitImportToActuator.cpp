/***********************************************************************************************************************
 *  OpenStudio(R), Copyright (c) 2008-2016, Alliance for Sustainable Energy, LLC. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 *  following conditions are met:
 *
 *  (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 *  disclaimer.
 *
 *  (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *  following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *  (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote
 *  products derived from this software without specific prior written permission from the respective party.
 *
 *  (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative
 *  works may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without
 *  specific prior written permission from Alliance for Sustainable Energy, LLC.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER, THE UNITED STATES GOVERNMENT, OR ANY CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **********************************************************************************************************************/

#include "ExternalInterfaceFunctionalMockupUnitImportToActuator.hpp"
#include "ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl.hpp"

#include "Model.hpp"
#include "Model_Impl.hpp"

#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/OS_ExternalInterface_FunctionalMockupUnitImport_To_Actuator_FieldEnums.hxx>

#include "../utilities/units/Unit.hpp"

#include "../utilities/core/Assert.hpp"

namespace openstudio {
namespace model {

namespace detail {

  ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl(const IdfObject& idfObject,
                                                                                                                         Model_Impl* model,
                                                                                                                         bool keepHandle)
    : ModelObject_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == ExternalInterfaceFunctionalMockupUnitImportToActuator::iddObjectType());
  }

  ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                                                                         Model_Impl* model,
                                                                                                                         bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == ExternalInterfaceFunctionalMockupUnitImportToActuator::iddObjectType());
  }

  ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl(const ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl& other,
                                                                                                                         Model_Impl* model,
                                                                                                                         bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::iddObjectType() const {
    return ExternalInterfaceFunctionalMockupUnitImportToActuator::iddObjectType();
  }

  ModelObject ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::actuatedComponentUnique() const {
    boost::optional<ModelObject> value = optionalActuatedComponentUnique();
    if (!value) {
      LOG_AND_THROW(briefDescription() << " does not have an Actuated Component Unique attached.");
    }
    return value.get();
  }

  std::string ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::actuatedComponentType() const {
    boost::optional<std::string> value = getString(OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::ActuatedComponentType,true);
    OS_ASSERT(value);
    return value.get();
  }

  std::string ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::actuatedComponentControlType() const {
    boost::optional<std::string> value = getString(OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::ActuatedComponentControlType,true);
    OS_ASSERT(value);
    return value.get();
  }

  ModelObject ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::fMUFile() const {
    boost::optional<ModelObject> value = optionalFMUFile();
    if (!value) {
      LOG_AND_THROW(briefDescription() << " does not have an FMUFile attached.");
    }
    return value.get();
  }

  std::string ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::fMUInstanceName() const {
    boost::optional<std::string> value = getString(OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::FMUInstanceName,true);
    OS_ASSERT(value);
    return value.get();
  }

  std::string ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::fMUVariableName() const {
    boost::optional<std::string> value = getString(OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::FMUVariableName,true);
    OS_ASSERT(value);
    return value.get();
  }

  double ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::initialValue() const {
    boost::optional<double> value = getDouble(OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::InitialValue,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::setActuatedComponentUnique(const ModelObject& modelObject) {
    bool result = setPointer(OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::ActuatedComponentUniqueName, modelObject.handle());
    return result;
  }

  void ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::setActuatedComponentType(const std::string& actuatedComponentType) {
    bool result = setString(OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::ActuatedComponentType, actuatedComponentType);
    OS_ASSERT(result);
  }

  void ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::setActuatedComponentControlType(const std::string& actuatedComponentControlType) {
    bool result = setString(OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::ActuatedComponentControlType, actuatedComponentControlType);
    OS_ASSERT(result);
  }

  bool ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::setFMUFile(const ModelObject& modelObject) {
    bool result = setPointer(OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::FMUFileName, modelObject.handle());
    return result;
  }

  void ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::setFMUInstanceName(const std::string& fMUInstanceName) {
    bool result = setString(OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::FMUInstanceName, fMUInstanceName);
    OS_ASSERT(result);
  }

  void ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::setFMUVariableName(const std::string& fMUVariableName) {
    bool result = setString(OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::FMUVariableName, fMUVariableName);
    OS_ASSERT(result);
  }

  void ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::setInitialValue(double initialValue) {
    bool result = setDouble(OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::InitialValue, initialValue);
    OS_ASSERT(result);
  }

  boost::optional<ModelObject> ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::optionalActuatedComponentUnique() const {
    return getObject<ModelObject>().getModelObjectTarget<ModelObject>(OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::ActuatedComponentUniqueName);
  }

  boost::optional<ModelObject> ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl::optionalFMUFile() const {
    return getObject<ModelObject>().getModelObjectTarget<ModelObject>(OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::FMUFileName);
  }

} // detail

ExternalInterfaceFunctionalMockupUnitImportToActuator::ExternalInterfaceFunctionalMockupUnitImportToActuator(const ModelObject& modelObject)
  : ModelObject(ExternalInterfaceFunctionalMockupUnitImportToActuator::iddObjectType(), modelObject.model())
{
  OS_ASSERT(getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  //     OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::ActuatedComponentUniqueName
  //     OS_ExternalInterface_FunctionalMockupUnitImport_To_ActuatorFields::FMUFileName
  bool ok = true;
  // ok = setActuatedComponentUnique();
  OS_ASSERT(ok);
  // setActuatedComponentType();
  // setActuatedComponentControlType();
  // ok = setFMUFile();
  OS_ASSERT(ok);
  // setFMUInstanceName();
  // setFMUVariableName();
  // setInitialValue();
}

IddObjectType ExternalInterfaceFunctionalMockupUnitImportToActuator::iddObjectType() {
  return IddObjectType(IddObjectType::OS_ExternalInterface_FunctionalMockupUnitImport_To_Actuator);
}

ModelObject ExternalInterfaceFunctionalMockupUnitImportToActuator::actuatedComponentUnique() const {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl>()->actuatedComponentUnique();
}

std::string ExternalInterfaceFunctionalMockupUnitImportToActuator::actuatedComponentType() const {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl>()->actuatedComponentType();
}

std::string ExternalInterfaceFunctionalMockupUnitImportToActuator::actuatedComponentControlType() const {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl>()->actuatedComponentControlType();
}

ModelObject ExternalInterfaceFunctionalMockupUnitImportToActuator::fMUFile() const {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl>()->fMUFile();
}

std::string ExternalInterfaceFunctionalMockupUnitImportToActuator::fMUInstanceName() const {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl>()->fMUInstanceName();
}

std::string ExternalInterfaceFunctionalMockupUnitImportToActuator::fMUVariableName() const {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl>()->fMUVariableName();
}

double ExternalInterfaceFunctionalMockupUnitImportToActuator::initialValue() const {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl>()->initialValue();
}

bool ExternalInterfaceFunctionalMockupUnitImportToActuator::setActuatedComponentUnique(const ModelObject& modelObject) {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl>()->setActuatedComponentUnique(modelObject);
}

void ExternalInterfaceFunctionalMockupUnitImportToActuator::setActuatedComponentType(const std::string& actuatedComponentType) {
  getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl>()->setActuatedComponentType(actuatedComponentType);
}

void ExternalInterfaceFunctionalMockupUnitImportToActuator::setActuatedComponentControlType(const std::string& actuatedComponentControlType) {
  getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl>()->setActuatedComponentControlType(actuatedComponentControlType);
}

bool ExternalInterfaceFunctionalMockupUnitImportToActuator::setFMUFile(const ModelObject& modelObject) {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl>()->setFMUFile(modelObject);
}

void ExternalInterfaceFunctionalMockupUnitImportToActuator::setFMUInstanceName(const std::string& fMUInstanceName) {
  getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl>()->setFMUInstanceName(fMUInstanceName);
}

void ExternalInterfaceFunctionalMockupUnitImportToActuator::setFMUVariableName(const std::string& fMUVariableName) {
  getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl>()->setFMUVariableName(fMUVariableName);
}

void ExternalInterfaceFunctionalMockupUnitImportToActuator::setInitialValue(double initialValue) {
  getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl>()->setInitialValue(initialValue);
}

/// @cond
ExternalInterfaceFunctionalMockupUnitImportToActuator::ExternalInterfaceFunctionalMockupUnitImportToActuator(std::shared_ptr<detail::ExternalInterfaceFunctionalMockupUnitImportToActuator_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio
