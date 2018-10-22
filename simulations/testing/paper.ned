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

package fognetsim.simulations.testing;
import fognetsim.node.compute.AccessPointCompute;
import fognetsim.node.compute.StandardCompute;
import fognetsim.node.compute.WirelessCompute;
import fognetsim.node.user.StandardUser;
import inet.node.inet.Router;
import inet.node.inet.StandardHost;
import inet.node.wireless.AccessPoint;
import ned.DatarateChannel;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;

//
// TODO documentation
//
network WirelessNetwork6
{
    parameters:
        int numb;
        int numbUsers;
    types:
        channel C extends DatarateChannel
        {
            datarate = 100Mbps;
            delay = 0.1us;

        }


    submodules:
        FogNode1: StandardCompute {
            @display("p=211,361;i=device/router");
        }
        FogNode2: StandardCompute {
            @display("p=475,488;i=device/router");
        }
        BaseBroker: StandardCompute {
            @display("p=566,361;i=device/server;q=Tasks");
        }
        userNode: WirelessCompute {
            @display("p=710,268;i=abstract/person");
        }
        router1: Router {
            @display("p=566,488;q=Tasks");
        }
        configurator: IPv4NetworkConfigurator {
            //config = xml("<config><interface user='*' address='145.236.16.2' netmask='255.255.255.0'/></config>");
            @display("p=205,31");
        }
        radioMedium: Ieee80211ScalarRadioMedium {
            @display("p=110,30");
        }
        FogNode3: StandardCompute {
            @display("p=475,275;i=device/router");
        }
        router2: Router {

            @display("p=304,361");
        }

        router11: Router {

            @display("p=845,361");
        }

        ap2: AccessPoint {
            @display("p=909,172");
        }
        ap: AccessPoint {
            @display("p=363,163");
        }

        ap1: AccessPoint {
            @display("p=783,172");
        }
        ap3: AccessPoint {
            @display("p=197,163");
        }

        ap4: AccessPoint {
            @display("p=566,163");
        }

        FogNode4: StandardCompute {
            @display("p=923,361;i=device/router");
        }
        router3: Router {

            @display("p=566,275");
        }

        userNode1: WirelessCompute {
            @display("p=320,59;i=abstract/person");
        }
        userNode2: WirelessCompute {
            @display("p=725,74;i=abstract/person");
        }
        userNode3: WirelessCompute {
            @display("p=109,128;i=abstract/person");
        }
        userNode4: WirelessCompute {
            @display("p=471,180;i=abstract/person");
        }
        userNode5: WirelessCompute {
            @display("p=109,251;i=abstract/person");
        }
        userNode6: WirelessCompute {
            @display("p=497,95;i=abstract/person");
        }
        mobile: WirelessCompute {
            @display("p=816,497;i=device/cellphone");
        }
        userNode8: WirelessCompute {
            @display("p=725,419;i=abstract/person");
        }
        userNode9: WirelessCompute {
            @display("p=421,419;i=abstract/person");
        }
        userNode10: WirelessCompute {
            @display("p=131,437;i=abstract/person");
        }
        userNode11: WirelessCompute {
            @display("p=922,290;i=abstract/person");
        }
        ap5: AccessPoint {
            @display("p=197,528");
        }

        ap6: AccessPoint {
            @display("p=909,528");
        }

        userNode12: WirelessCompute {
            @display("p=870,74;i=abstract/person");
        }
        mobile1: WirelessCompute {
            @display("p=274,144;i=device/cellphone");
        }
        mobile2: WirelessCompute {
            @display("p=344,503;i=device/cellphone");
        }
        staticSensor: StandardHost {
            @display("p=301,451;i=misc/node");
        }
        mobile3: WirelessCompute {
            @display("p=679,164;i=device/cellphone");
        }
        laptopUser: WirelessCompute {
            @display("p=589,31");
        }
    connections:



        router1.ethg++ <--> C <--> BaseBroker.ethg++;
        router2.ethg++ <--> C <--> FogNode1.ethg++;
        router1.ethg++ <--> C <--> FogNode2.ethg++;
        router3.ethg++ <--> C <--> FogNode3.ethg++;
        router11.ethg++ <--> C <--> FogNode4.ethg++;
        router2.ethg++ <--> C <--> BaseBroker.ethg++;
        router11.ethg++ <--> C <--> BaseBroker.ethg++;

        router2.ethg++ <--> C <--> ap.ethg++;
        router3.ethg++ <--> C <--> BaseBroker.ethg++;
        router3.ethg++ <--> C <--> ap4.ethg++;
        router11.ethg++ <--> C <--> ap2.ethg++;
        router2.ethg++ <--> C <--> ap.ethg++;
        router11.ethg++ <--> C <--> ap1.ethg++;
        router2.ethg++ <--> C <--> ap3.ethg++;
        router2.ethg++ <--> C <--> ap5.ethg++;
        router11.ethg++ <--> C <--> ap6.ethg++;
        router2.ethg++ <--> C <--> staticSensor.ethg++;
}

