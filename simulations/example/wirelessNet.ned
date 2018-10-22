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

package fognetsim.simulations.example;
import fognetsim.node.compute.AccessPointCompute;
import fognetsim.node.compute.StandardCompute;
import fognetsim.node.compute.WirelessCompute;
import inet.node.inet.Router;
import ned.DatarateChannel;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;

//
// TODO documentation
//
network WirelessNet
{
    parameters:

        @display("bgb=784,1014");
    types:
        channel C extends DatarateChannel
        {
            datarate = 100Mbps;
            delay = 0.1us;
        }

    submodules:
        ComputeBroker1: StandardCompute {
            @display("p=146,888;i=device/router");
        }
        ComputeBroker2: StandardCompute {
            @display("p=271,888;i=device/router");
        }
        ComputeBroker3: StandardCompute {
            @display("p=652,888;i=device/router");
        }
        ComputeBroker4: StandardCompute {
            @display("p=521,888;i=device/router");
        }
        ComputeBroker5: StandardCompute {
            @display("p=393,888;i=device/router");
        }
        BaseBroker: StandardCompute {
            @display("p=379,664;i=device/server;q=Tasks");
        }
        ap3: AccessPointCompute {

            @display("p=374,185");
        }
        ap5: AccessPointCompute {

            @display("p=654,508");
        }
        ap: AccessPointCompute {

            @display("p=109,508");
        }
        user: WirelessCompute {
            @display("p=384,449");
        }
        routerD: Router {
            @display("p=379,745;q=Tasks");
        }
        configurator: IPv4NetworkConfigurator {
            //config = xml("<config><interface user='*' address='145.236.16.2' netmask='255.255.255.0'/></config>");
            @display("p=140,50");
        }
        radioMedium: Ieee80211ScalarRadioMedium {
            @display("p=60,50");
        }

        router1: Router {
            @display("p=261,575");
        }
        router3: Router {
            @display("p=379,365");
        }
        router5: Router {
            @display("p=501,563");
        }
    connections:
        ap5.ethg++ <--> C <--> ap.ethg++;
        ap3.ethg++ <--> C <--> ap.ethg++;
        //ap3.ethg++ <--> C <--> ap5.ethg++;

        ap.ethg++ <--> C <--> router1.ethg++;
        ap3.ethg++ <--> C <--> router3.ethg++;
        ap5.ethg++ <--> C <--> router5.ethg++;

        router1.ethg++ <--> C <--> BaseBroker.ethg++;
        router3.ethg++ <--> C <--> BaseBroker.ethg++;
        router5.ethg++ <--> C <--> BaseBroker.ethg++;



        routerD.ethg++ <--> C <--> BaseBroker.ethg++;
        routerD.ethg++ <--> C <--> ComputeBroker1.ethg++;
        routerD.ethg++ <--> C <--> ComputeBroker2.ethg++;
        routerD.ethg++ <--> C <--> ComputeBroker3.ethg++;
        routerD.ethg++ <--> C <--> ComputeBroker4.ethg++;
        routerD.ethg++ <--> C <--> ComputeBroker5.ethg++;
}

