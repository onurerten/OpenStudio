/**********************************************************************
 *  Copyright (c) 2008-2015, Alliance for Sustainable Energy.
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

#include "PlantComponentTemperatureSource.hpp"
#include "PlantComponentTemperatureSource_Impl.hpp"

#include "Schedule.hpp"
#include "Schedule_Impl.hpp"
#include "../../model/ScheduleTypeLimits.hpp"
#include "../../model/ScheduleTypeRegistry.hpp"

#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/OS_PlantComponent_TemperatureSource_FieldEnums.hxx>

#include "../utilities/units/Unit.hpp"

#include "../utilities/core/Assert.hpp"

namespace openstudio {
namespace model {

namespace detail {

  PlantComponentTemperatureSource_Impl::PlantComponentTemperatureSource_Impl(const IdfObject& idfObject,
                                                                             Model_Impl* model,
                                                                             bool keepHandle)
    : StraightComponent_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == PlantComponentTemperatureSource::iddObjectType());
  }

  PlantComponentTemperatureSource_Impl::PlantComponentTemperatureSource_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                             Model_Impl* model,
                                                                             bool keepHandle)
    : StraightComponent_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == PlantComponentTemperatureSource::iddObjectType());
  }

  PlantComponentTemperatureSource_Impl::PlantComponentTemperatureSource_Impl(const PlantComponentTemperatureSource_Impl& other,
                                                                             Model_Impl* model,
                                                                             bool keepHandle)
    : StraightComponent_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& PlantComponentTemperatureSource_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType PlantComponentTemperatureSource_Impl::iddObjectType() const {
    return PlantComponentTemperatureSource::iddObjectType();
  }

  std::vector<ScheduleTypeKey> PlantComponentTemperatureSource_Impl::getScheduleTypeKeys(const Schedule& schedule) const
  {
    // TODO: Check schedule display names.
    std::vector<ScheduleTypeKey> result;
    UnsignedVector fieldIndices = getSourceIndices(schedule.handle());
    UnsignedVector::const_iterator b(fieldIndices.begin()), e(fieldIndices.end());
    if (std::find(b,e,OS_PlantComponent_TemperatureSourceFields::SourceTemperatureScheduleName) != e)
    {
      result.push_back(ScheduleTypeKey("PlantComponentTemperatureSource","Source Temperature"));
    }
    return result;
  }

  unsigned PlantComponentTemperatureSource_Impl::inletPort()
  {
    return OS_PlantComponent_TemperatureSourceFields::InletNode;
  }

  unsigned PlantComponentTemperatureSource_Impl::outletPort()
  {
    return OS_PlantComponent_TemperatureSourceFields::OutletNode;
  }

  boost::optional<double> PlantComponentTemperatureSource_Impl::designVolumeFlowRate() const {
    return getDouble(OS_PlantComponent_TemperatureSourceFields::DesignVolumeFlowRate,true);
  }

  bool PlantComponentTemperatureSource_Impl::isDesignVolumeFlowRateAutosized() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_PlantComponent_TemperatureSourceFields::DesignVolumeFlowRate, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autosize");
    }
    return result;
  }

  std::string PlantComponentTemperatureSource_Impl::temperatureSpecificationType() const {
    boost::optional<std::string> value = getString(OS_PlantComponent_TemperatureSourceFields::TemperatureSpecificationType,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<double> PlantComponentTemperatureSource_Impl::sourceTemperature() const {
    return getDouble(OS_PlantComponent_TemperatureSourceFields::SourceTemperature,true);
  }

  boost::optional<Schedule> PlantComponentTemperatureSource_Impl::sourceTemperatureSchedule() const {
    return getObject<ModelObject>().getModelObjectTarget<Schedule>(OS_PlantComponent_TemperatureSourceFields::SourceTemperatureScheduleName);
  }

  bool PlantComponentTemperatureSource_Impl::setDesignVolumeFlowRate(boost::optional<double> designVolumeFlowRate) {
    bool result(false);
    if (designVolumeFlowRate) {
      result = setDouble(OS_PlantComponent_TemperatureSourceFields::DesignVolumeFlowRate, designVolumeFlowRate.get());
    }
    return result;
  }

  void PlantComponentTemperatureSource_Impl::autosizeDesignVolumeFlowRate() {
    bool result = setString(OS_PlantComponent_TemperatureSourceFields::DesignVolumeFlowRate, "autosize");
    OS_ASSERT(result);
  }

  bool PlantComponentTemperatureSource_Impl::setTemperatureSpecificationType(std::string temperatureSpecificationType) {
    bool result = setString(OS_PlantComponent_TemperatureSourceFields::TemperatureSpecificationType, temperatureSpecificationType);
    return result;
  }

  void PlantComponentTemperatureSource_Impl::setSourceTemperature(boost::optional<double> sourceTemperature) {
    bool result(false);
    if (sourceTemperature) {
      result = setDouble(OS_PlantComponent_TemperatureSourceFields::SourceTemperature, sourceTemperature.get());
    }
    else {
      resetSourceTemperature();
      result = true;
    }
    OS_ASSERT(result);
  }

  void PlantComponentTemperatureSource_Impl::resetSourceTemperature() {
    bool result = setString(OS_PlantComponent_TemperatureSourceFields::SourceTemperature, "");
    OS_ASSERT(result);
  }

  bool PlantComponentTemperatureSource_Impl::setSourceTemperatureSchedule(Schedule& schedule) {
    bool result = setSchedule(OS_PlantComponent_TemperatureSourceFields::SourceTemperatureScheduleName,
                              "PlantComponentTemperatureSource",
                              "Source Temperature",
                              schedule);
    return result;
  }

  void PlantComponentTemperatureSource_Impl::resetSourceTemperatureSchedule() {
    bool result = setString(OS_PlantComponent_TemperatureSourceFields::SourceTemperatureScheduleName, "");
    OS_ASSERT(result);
  }

} // detail

PlantComponentTemperatureSource::PlantComponentTemperatureSource(const Model& model)
  : StraightComponent(PlantComponentTemperatureSource::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::PlantComponentTemperatureSource_Impl>());

  bool ok = true;
  autosizeDesignVolumeFlowRate();
  ok = setTemperatureSpecificationType( "Constant" );
  OS_ASSERT(ok);
  setSourceTemperature( 8 );
}

IddObjectType PlantComponentTemperatureSource::iddObjectType() {
  return IddObjectType(IddObjectType::OS_PlantComponent_TemperatureSource);
}

std::vector<std::string> PlantComponentTemperatureSource::temperatureSpecificationTypeValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_PlantComponent_TemperatureSourceFields::TemperatureSpecificationType);
}

boost::optional<double> PlantComponentTemperatureSource::designVolumeFlowRate() const {
  return getImpl<detail::PlantComponentTemperatureSource_Impl>()->designVolumeFlowRate();
}

bool PlantComponentTemperatureSource::isDesignVolumeFlowRateAutosized() const {
  return getImpl<detail::PlantComponentTemperatureSource_Impl>()->isDesignVolumeFlowRateAutosized();
}

std::string PlantComponentTemperatureSource::temperatureSpecificationType() const {
  return getImpl<detail::PlantComponentTemperatureSource_Impl>()->temperatureSpecificationType();
}

boost::optional<double> PlantComponentTemperatureSource::sourceTemperature() const {
  return getImpl<detail::PlantComponentTemperatureSource_Impl>()->sourceTemperature();
}

boost::optional<Schedule> PlantComponentTemperatureSource::sourceTemperatureSchedule() const {
  return getImpl<detail::PlantComponentTemperatureSource_Impl>()->sourceTemperatureSchedule();
}

bool PlantComponentTemperatureSource::setDesignVolumeFlowRate(double designVolumeFlowRate) {
  return getImpl<detail::PlantComponentTemperatureSource_Impl>()->setDesignVolumeFlowRate(designVolumeFlowRate);
}

void PlantComponentTemperatureSource::autosizeDesignVolumeFlowRate() {
  getImpl<detail::PlantComponentTemperatureSource_Impl>()->autosizeDesignVolumeFlowRate();
}

bool PlantComponentTemperatureSource::setTemperatureSpecificationType(std::string temperatureSpecificationType) {
  return getImpl<detail::PlantComponentTemperatureSource_Impl>()->setTemperatureSpecificationType(temperatureSpecificationType);
}

void PlantComponentTemperatureSource::setSourceTemperature(double sourceTemperature) {
  getImpl<detail::PlantComponentTemperatureSource_Impl>()->setSourceTemperature(sourceTemperature);
}

void PlantComponentTemperatureSource::resetSourceTemperature() {
  getImpl<detail::PlantComponentTemperatureSource_Impl>()->resetSourceTemperature();
}

bool PlantComponentTemperatureSource::setSourceTemperatureSchedule(Schedule& schedule) {
  return getImpl<detail::PlantComponentTemperatureSource_Impl>()->setSourceTemperatureSchedule(schedule);
}

void PlantComponentTemperatureSource::resetSourceTemperatureSchedule() {
  getImpl<detail::PlantComponentTemperatureSource_Impl>()->resetSourceTemperatureSchedule();
}

/// @cond
PlantComponentTemperatureSource::PlantComponentTemperatureSource(std::shared_ptr<detail::PlantComponentTemperatureSource_Impl> impl)
  : StraightComponent(impl)
{}
/// @endcond

} // model
} // openstudio
