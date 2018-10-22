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
import ned.DatarateChannel;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;

//
// TODO documentation
//
network WirelessNetwork3
{
    parameters:
        int numb;
        int numbUsers;
        @display("bgb=772,645");
    types:
        channel C extends DatarateChannel
        {
            datarate = 100Mbps;
            delay = 0.1us;
        }

    submodules:
        ComputeBroker1: StandardCompute {
            @display("p=123,596;i=device/router");
        }
        ComputeBroker2: StandardCompute {
            @display("p=293,596;i=device/router");
        }
        BaseBroker: StandardCompute {
            @display("p=293,375;i=device/server;q=Tasks");
        }
        user[numbUsers]: WirelessCompute {
            @display("p=248,214");
        }
        router1: Router {
            @display("p=293,532;q=Tasks");
        }
        configurator: IPv4NetworkConfigurator {
            //config = xml("<config><interface user='*' address='145.236.16.2' netmask='255.255.255.0'/></config>");
            @display("p=140,50");
        }
        radioMedium: Ieee80211ScalarRadioMedium {
            @display("p=60,50");
        }
        ComputeBroker3: StandardCompute {
            @display("p=467,596;i=device/router");
        }
        ap[numb]: AccessPointCompute {


            @display("p=293,123");
        }
        routerL3[numb]: Router {
            @display("p=293,286");
        }
    connections:
        router1.ethg++ <--> C <--> BaseBroker.ethg++;
        router1.ethg++ <--> C <--> ComputeBroker1.ethg++;
        router1.ethg++ <--> C <--> ComputeBroker2.ethg++;
        router1.ethg++ <--> C <--> ComputeBroker3.ethg++;

        for i=0..(numb-2) {
            ap[i].ethg++ <--> C <--> ap[i+1].ethg++;
            routerL3[i].ethg++ <--> C <--> ap[i].ethg++;
            routerL3[i].ethg++ <--> C <--> BaseBroker.ethg++;
        }


}

