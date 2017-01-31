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

#include "ExternalInterfaceFunctionalMockupUnitImportToSchedule.hpp"
#include "ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl.hpp"

// TODO: Check the following class names against object getters and setters.
#include "ScheduleTypeLimits.hpp"
#include "ScheduleTypeLimits_Impl.hpp"

#include "Model.hpp"
#include "Model_Impl.hpp"

#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/OS_ExternalInterface_FunctionalMockupUnitImport_To_Schedule_FieldEnums.hxx>

#include "../utilities/units/Unit.hpp"

#include "../utilities/core/Assert.hpp"

namespace openstudio {
namespace model {

namespace detail {

  ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl(const IdfObject& idfObject,
                                                                                                                         Model_Impl* model,
                                                                                                                         bool keepHandle)
    : ModelObject_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == ExternalInterfaceFunctionalMockupUnitImportToSchedule::iddObjectType());
  }

  ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                                                                         Model_Impl* model,
                                                                                                                         bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == ExternalInterfaceFunctionalMockupUnitImportToSchedule::iddObjectType());
  }

  ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl(const ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl& other,
                                                                                                                         Model_Impl* model,
                                                                                                                         bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::iddObjectType() const {
    return ExternalInterfaceFunctionalMockupUnitImportToSchedule::iddObjectType();
  }

  boost::optional<ScheduleTypeLimits> ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::scheduleTypeLimitss() const {
    return getObject<ModelObject>().getModelObjectTarget<ScheduleTypeLimits>(OS_ExternalInterface_FunctionalMockupUnitImport_To_ScheduleFields::ScheduleTypeLimitsNames);
  }

  ModelObject ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::fMUFile() const {
    boost::optional<ModelObject> value = optionalFMUFile();
    if (!value) {
      LOG_AND_THROW(briefDescription() << " does not have an FMUFile attached.");
    }
    return value.get();
  }

  std::string ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::fMUInstanceName() const {
    boost::optional<std::string> value = getString(OS_ExternalInterface_FunctionalMockupUnitImport_To_ScheduleFields::FMUInstanceName,true);
    OS_ASSERT(value);
    return value.get();
  }

  std::string ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::fMUVariableName() const {
    boost::optional<std::string> value = getString(OS_ExternalInterface_FunctionalMockupUnitImport_To_ScheduleFields::FMUVariableName,true);
    OS_ASSERT(value);
    return value.get();
  }

  double ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::initialValue() const {
    boost::optional<double> value = getDouble(OS_ExternalInterface_FunctionalMockupUnitImport_To_ScheduleFields::InitialValue,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::setScheduleTypeLimitss(const ScheduleTypeLimits& scheduleTypeLimits) {
    bool result = setPointer(OS_ExternalInterface_FunctionalMockupUnitImport_To_ScheduleFields::ScheduleTypeLimitsNames, scheduleTypeLimits.handle());
    return result;
  }

  void ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::resetScheduleTypeLimitss() {
    bool result = setString(OS_ExternalInterface_FunctionalMockupUnitImport_To_ScheduleFields::ScheduleTypeLimitsNames, "");
    OS_ASSERT(result);
  }

  bool ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::setFMUFile(const ModelObject& fMUFileName) {
    bool result = setPointer(OS_ExternalInterface_FunctionalMockupUnitImport_To_ScheduleFields::FMUFileName, fMUFileName.handle());
    return result;
  }

  void ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::setFMUInstanceName(const std::string& fMUInstanceName) {
    bool result = setString(OS_ExternalInterface_FunctionalMockupUnitImport_To_ScheduleFields::FMUInstanceName, fMUInstanceName);
    OS_ASSERT(result);
  }

  void ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::setFMUVariableName(const std::string& fMUVariableName) {
    bool result = setString(OS_ExternalInterface_FunctionalMockupUnitImport_To_ScheduleFields::FMUVariableName, fMUVariableName);
    OS_ASSERT(result);
  }

  void ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::setInitialValue(double initialValue) {
    bool result = setDouble(OS_ExternalInterface_FunctionalMockupUnitImport_To_ScheduleFields::InitialValue, initialValue);
    OS_ASSERT(result);
  }

  boost::optional<ModelObject> ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl::optionalFMUFile() const {
    return getObject<ModelObject>().getModelObjectTarget<ModelObject>(OS_ExternalInterface_FunctionalMockupUnitImport_To_ScheduleFields::FMUFileName);
  }

} // detail

ExternalInterfaceFunctionalMockupUnitImportToSchedule::ExternalInterfaceFunctionalMockupUnitImportToSchedule(const Model& model)
  : ModelObject(ExternalInterfaceFunctionalMockupUnitImportToSchedule::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  //     OS_ExternalInterface_FunctionalMockupUnitImport_To_ScheduleFields::FMUFileName
  bool ok = true;
  // ok = setFMUFile();
  OS_ASSERT(ok);
  // setFMUInstanceName();
  // setFMUVariableName();
  // setInitialValue();
}

IddObjectType ExternalInterfaceFunctionalMockupUnitImportToSchedule::iddObjectType() {
  return IddObjectType(IddObjectType::OS_ExternalInterface_FunctionalMockupUnitImport_To_Schedule);
}

boost::optional<ScheduleTypeLimits> ExternalInterfaceFunctionalMockupUnitImportToSchedule::scheduleTypeLimitss() const {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl>()->scheduleTypeLimitss();
}

ModelObject ExternalInterfaceFunctionalMockupUnitImportToSchedule::fMUFile() const {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl>()->fMUFile();
}

std::string ExternalInterfaceFunctionalMockupUnitImportToSchedule::fMUInstanceName() const {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl>()->fMUInstanceName();
}

std::string ExternalInterfaceFunctionalMockupUnitImportToSchedule::fMUVariableName() const {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl>()->fMUVariableName();
}

double ExternalInterfaceFunctionalMockupUnitImportToSchedule::initialValue() const {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl>()->initialValue();
}

bool ExternalInterfaceFunctionalMockupUnitImportToSchedule::setScheduleTypeLimitss(const ScheduleTypeLimits& scheduleTypeLimits) {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl>()->setScheduleTypeLimitss(scheduleTypeLimits);
}

void ExternalInterfaceFunctionalMockupUnitImportToSchedule::resetScheduleTypeLimitss() {
  getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl>()->resetScheduleTypeLimitss();
}

bool ExternalInterfaceFunctionalMockupUnitImportToSchedule::setFMUFile(const ModelObject& fMUFileName) {
  return getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl>()->setFMUFile(fMUFileName);
}

void ExternalInterfaceFunctionalMockupUnitImportToSchedule::setFMUInstanceName(const std::string& fMUInstanceName) {
  getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl>()->setFMUInstanceName(fMUInstanceName);
}

void ExternalInterfaceFunctionalMockupUnitImportToSchedule::setFMUVariableName(const std::string& fMUVariableName) {
  getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl>()->setFMUVariableName(fMUVariableName);
}

void ExternalInterfaceFunctionalMockupUnitImportToSchedule::setInitialValue(double initialValue) {
  getImpl<detail::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl>()->setInitialValue(initialValue);
}

/// @cond
ExternalInterfaceFunctionalMockupUnitImportToSchedule::ExternalInterfaceFunctionalMockupUnitImportToSchedule(std::shared_ptr<detail::ExternalInterfaceFunctionalMockupUnitImportToSchedule_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio
