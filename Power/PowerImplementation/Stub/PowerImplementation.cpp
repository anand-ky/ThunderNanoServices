/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#include "Module.h"
#include <interfaces/IPower.h>

namespace WPEFramework {

class PowerImplementation : public Exchange::IPower {
private:
    PowerImplementation(const PowerImplementation&) = delete;
    PowerImplementation& operator=(const PowerImplementation&) = delete;

public:
    PowerImplementation()
    {
        _currentState = PCState::On;
        TRACE(Trace::Information, (_T("PowerImplementation::Construct()")));
    }

    virtual ~PowerImplementation()
    {
        TRACE(Trace::Information, (_T("PowerImplementation::Destruct()")));
    }

    BEGIN_INTERFACE_MAP(PowerImplementation)
    INTERFACE_ENTRY(Exchange::IPower)
    END_INTERFACE_MAP

    // IPower methods
    virtual PCState GetState() const override
    {
        TRACE(Trace::Information, (_T("PowerImplementation::GetState() => %d"), _currentState));
        return (_currentState);
    }
    virtual PCStatus SetState(const PCState state, const uint32_t waitTime) override
    {

        TRACE(Trace::Information, (_T("PowerImplementation::SetState(%d, %d) => PCSuccess"), state, waitTime));

        _currentState = state;

        return (PCSuccess);
    }
    virtual void PowerKey() override
    {
        TRACE(Trace::Information, (_T("PowerImplementation::PowerKey()")));
    }
    virtual void Configure(const string& settings)
    {
        TRACE(Trace::Information, (_T("PowerImplementation::Configure()")));
    }
    virtual void Register(Exchange::IPower::INotification* sink) override
    {
        TRACE(Trace::Information, (_T("PowerImplementation::Register()")));
    }
    virtual void Unregister(Exchange::IPower::INotification* sink) override
    {
        TRACE(Trace::Information, (_T("PowerImplementation::Unregister()")));
    }

private:
    PCState _currentState;
};

// The essence of making the IPower interface available. This instantiates
// an object that can be created from the outside of the library by looking
// for the PowerImplementation class name, that realizes the IPower interface.
SERVICE_REGISTRATION(PowerImplementation, 1, 0);
}
