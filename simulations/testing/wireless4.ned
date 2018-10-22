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
import inet.node.inet.Router;
import inet.node.wireless.AccessPoint;
import ned.DatarateChannel;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;

//
// TODO documentation
//
network WirelessNetwork4
{
    parameters:
        int numb;
        int numbUsers;
        @display("bgb=1137,750");
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
        user[numbUsers]: WirelessCompute {
            @display("p=548,161;i=abstract/person");
        }
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
            @display("p=756,616;i=device/router");
        }
        ap1: AccessPointCompute {


            @display("i=abstract/accesspoint;p=60,259");
        }
        router2: Router {

            @display("p=60,330");
        }

        router3: Router {

            @display("p=177,330");
        }

        router4: Router {

            @display("p=298,330");
        }

        router5: Router {

            @display("p=422,330");
        }

        router6: Router {

            @display("p=529,330");
        }

        router7: Router {

            @display("p=634,330");
        }

        router8: Router {

            @display("p=742,330");
        }

        router9: Router {

            @display("p=834,330");
        }

        router10: Router {

            @display("p=954,330");
        }

        router11: Router {

            @display("p=1074,330");
        }

        ap2: AccessPointCompute {


            @display("p=177,259");
        }
        ap3: AccessPointCompute {


            @display("p=298,259");
        }
        ap4: AccessPointCompute {


            @display("p=422,259");
        }
        ap5: AccessPointCompute {


            @display("p=529,259");
        }
        ap6: AccessPointCompute {


            @display("p=634,259");
        }
        ap7: AccessPointCompute {


            @display("p=742,259");
        }
        ap8: AccessPointCompute {


            @display("p=834,259");
        }
        ap9: AccessPointCompute {


            @display("p=954,259");
        }
        ap10: AccessPointCompute {


            @display("p=1074,259");
        }
    connections:
        
        
        
        router1.ethg++ <--> C <--> BaseBroker.ethg++;
        router1.ethg++ <--> C <--> ComputeBroker1.ethg++;
        router1.ethg++ <--> C <--> ComputeBroker2.ethg++;
        router1.ethg++ <--> C <--> ComputeBroker3.ethg++;

        router2.ethg++ <--> C <--> BaseBroker.ethg++;
        router3.ethg++ <--> C <--> BaseBroker.ethg++;
        router4.ethg++ <--> C <--> BaseBroker.ethg++;
        router5.ethg++ <--> C <--> BaseBroker.ethg++;
        router6.ethg++ <--> C <--> BaseBroker.ethg++;
        router7.ethg++ <--> C <--> BaseBroker.ethg++;
        router8.ethg++ <--> C <--> BaseBroker.ethg++;
        router9.ethg++ <--> C <--> BaseBroker.ethg++;
        router10.ethg++ <--> C <--> BaseBroker.ethg++;
        router11.ethg++ <--> C <--> BaseBroker.ethg++;

        router2.ethg++ <--> C <--> ap1.ethg++;
        router3.ethg++ <--> C <--> ap2.ethg++;
        router4.ethg++ <--> C <--> ap3.ethg++;
        router5.ethg++ <--> C <--> ap4.ethg++;
        router6.ethg++ <--> C <--> ap5.ethg++;
        router7.ethg++ <--> C <--> ap6.ethg++;
        router8.ethg++ <--> C <--> ap7.ethg++;
        router9.ethg++ <--> C <--> ap8.ethg++;
        router10.ethg++ <--> C <--> ap9.ethg++;
        router11.ethg++ <--> C <--> ap10.ethg++;
        router2.ethg++ <--> C <--> ap1.ethg++;


        ap1.ethg++ <--> C <--> ap2.ethg++;
        ap2.ethg++ <--> C <--> ap3.ethg++;
        
        ap3.ethg++ <--> C <--> ap4.ethg++;
        ap4.ethg++ <--> C <--> ap5.ethg++;
        ap5.ethg++ <--> C <--> ap6.ethg++;
        ap6.ethg++ <--> C <--> ap7.ethg++;
        ap7.ethg++ <--> C <--> ap8.ethg++;
        ap8.ethg++ <--> C <--> ap9.ethg++;
        ap9.ethg++ <--> C <--> ap10.ethg++;

}

