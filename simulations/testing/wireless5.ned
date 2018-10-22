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
import inet.node.wireless.AccessPoint;
import ned.DatarateChannel;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;
import inet.common.lifecycle.LifecycleController;

//
// TODO documentation
//
network WirelessNetwork5
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
        ComputeBroker1: StandardCompute {
            @display("p=412,616;i=device/router");
        }
        ComputeBroker2: StandardCompute {
            @display("p=582,616;i=device/router");
        }
        BaseBroker: StandardCompute {
            @display("p=582,424;i=device/server;q=Tasks");
        }
        user[numbUsers]: WirelessCompute;
        router1: Router {
            @display("p=582,552;q=Tasks");
        }
        configurator: IPv4NetworkConfigurator {
            //config = xml("<config><interface user='*' address='145.236.16.2' netmask='255.255.255.0'/></config>");
            @display("p=222,50");
        }
        radioMedium: Ieee80211ScalarRadioMedium {
            @display("p=60,50");
        }
        ComputeBroker3: StandardCompute {
            @display("p=718,616;i=device/router");
        }
        router2: Router {

            @display("p=304,361");
        }

        router11: Router {

            @display("p=845,361");
        }

        ap2: AccessPoint {
            @display("p=997,172");
        }
        ap: AccessPoint {
            @display("p=133,172");
        }

        ap1: AccessPoint {
            @display("p=997,566");
        }
        ap3: AccessPoint {
            @display("p=139,566");
        }

        ap4: AccessPoint {
            @display("p=582,330");
        }

        ComputeBroker4: StandardCompute {
            @display("p=858,616;i=device/router");
        }
        lifecycleController: LifecycleController {
            @display("p=50,50");
        }
    connections:



        router1.ethg++ <--> C <--> BaseBroker.ethg++;
        router1.ethg++ <--> C <--> ComputeBroker1.ethg++;
        router1.ethg++ <--> C <--> ComputeBroker2.ethg++;
        router1.ethg++ <--> C <--> ComputeBroker3.ethg++;
        router1.ethg++ <--> C <--> ComputeBroker4.ethg++;

        router2.ethg++ <--> C <--> BaseBroker.ethg++;
        router11.ethg++ <--> C <--> BaseBroker.ethg++;

        router2.ethg++ <--> C <--> ap.ethg++;
        router11.ethg++ <--> C <--> ap2.ethg++;
        router2.ethg++ <--> C <--> ap.ethg++;
        router11.ethg++ <--> C <--> ap1.ethg++;
        router2.ethg++ <--> C <--> ap3.ethg++;
        ap4.ethg++ <--> C <--> BaseBroker.ethg++;

        ap4.ethg++ <--> C <--> ap.ethg++;
        ap4.ethg++ <--> C <--> ap1.ethg++;
        ap4.ethg++ <--> C <--> ap2.ethg++;
        ap4.ethg++ <--> C <--> ap3.ethg++;



}

