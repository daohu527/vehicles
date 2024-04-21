# vehicles
Apollo vehicle protocol based on [opendbc](https://github.com/commaai/opendbc)

# Vehicle List

| Vehicle Type | Image                                         | DBC File                         | Tested |
|--------------|-----------------------------------------------|----------------------------------|--------|
| Acura ILX    | <img src=docs/acura_ilx_2016.jpg width ="100"> | acura_ilx_2016_can_generated.d   | no     |
| Acura ILX    |                                               | acura_ilx_2016_nidec.dbc         | no     |
| Acura RDX    |                                               | acura_rdx_2018_can_generated.dbc | no     |
| Acura RDX    |                                               | acura_rdx_2020_can_generated.dbc | no     |
| BMW e9x/e8x  |                                               | bmw_e9x_e8x.dbc                  | no     |
| Cadillac CT6 |                                               | cadillac_ct6_chassis.dbc         | no     |
| Cadillac CT6 |                                               | cadillac_ct6_object.dbc          | no     |
| Cadillac CT6 |                                               | cadillac_ct6_powertrain.dbc      | no     |

# Quick start

## How to generate
```shell
adbctool -f ../opendbc/acura_ilx_2016_can_generated.dbc -t acura_ilx -o acura_ilx/
```
