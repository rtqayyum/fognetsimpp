//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

namespace inet;

cplusplus {{
        #include "inet/common/INETDefs.h"
        #include "MqttMsgBase_m.h"
}}
packet MqttMsgBase;

//
// TODO generated message class
//
packet MqttMsgConnect {
        int expectedReplyLength; // in bytes
        double replyDelay;       // reply after this many seconds
        bool serverClose; 
        
        string type;
        // duplicate delivery
        bool dupFlag;
        // quality of service level
        int qosLevel;
        // retain flag
        bool retain;
        // message identifier
        string messageId;
        
        // protocol name
        string protocolName;
        // protocol version
        string protocolVersion;
        // client identifier
        string clientId;
        // will retain flag
        bool willRetain;
        // will quality of service level
        string willQosLevel;
        // will flag
        bool willFlag;
        // will topic
        string willTopic;
        // will message
        string willMessage;
        // username
        string username;
        // password
        string password;
        // clean session flag
        bool cleanSession;
        // keep alive period (in sec)
        unsigned short keepAlivePeriod;
        
        bool isBroker;
}
