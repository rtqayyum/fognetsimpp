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
import fognetsim.node.compute.StandardCompute;
import fognetsim.node.user.StandardUser;
import inet.node.inet.Router;
import ned.DatarateChannel;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;

//
// TODO documentation
//
network Network
{
    parameters:

        @display("bgb=486,309");
    types:
        channel C extends DatarateChannel
        {
            datarate = 100Mbps;
            delay = 0.1us;

        }


    submodules:
        router: Router {
            @display("p=226,148");
        }
        baseBroker: StandardCompute {
            @display("p=401,148;i=device/server");
        }
        standardUser: StandardUser {
            @display("p=60,148");
        }
        configurator: IPv4NetworkConfigurator {
            //config = xml("<config><interface host='*' address='145.236.x.x' netmask='255.255.0.0'/></config>");
            @display("p=140,50");
        }

        computeBroker: StandardCompute {
            @display("p=165,274;i=device/router");
        }
        standardUser1: StandardUser {
            @display("p=226,38");
        }
        computeBroker1: StandardCompute {
            @display("p=281,274;i=device/router");
        }
    connections:
        standardUser.ethg++ <--> C <--> router.ethg++;
        standardUser1.ethg++ <--> C <--> router.ethg++;
        router.ethg++ <--> C <--> baseBroker.ethg++;
        router.ethg++ <--> C <--> computeBroker.ethg++;
        router.ethg++ <--> C <--> computeBroker1.ethg++;
}

