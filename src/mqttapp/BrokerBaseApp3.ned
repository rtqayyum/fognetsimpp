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

package inet.applications.mqttapp;
import inet.applications.contract.IUDPApp;


simple BrokerBaseApp3 like IUDPApp
{
    parameters:
        string interfaceTableModule;   // The path to the InterfaceTable module
        int localPort;  // local port to listen on
        int MIPS=default(1000);
        int algo=default(0);
        
                
        @display("i=block/app");
        @signal[pk](type=cPacket);
        @statistic[echoedPk](title="packets echoed"; source=pk; record=count,"sum(packetBytes)","vector(packetBytes)"; interpolationmode=none);
  		@signal[delay](type="float");
		@statistic[delay](title="delay"; source="delay"; record=stats, vector; interpolationmode=none);   
    gates:
        input udpIn @labels(UDPControlInfo/up);
        output udpOut @labels(UDPControlInfo/down);
}