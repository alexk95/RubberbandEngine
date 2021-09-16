# RubberbandEngine
(Still in development)

The RubberbandEngine is designed to take over the computation of the required points to display a rubberband in a CAD application.

The engine is designed to work with primitive types to compute the rubberband such as:
- Lines between two Points
- Circles around a midpoint with a given radius and orientation
- more options coming.


___
# Setup engine from JSON

The engine can be set by means of a json object.

All members and fixed values used in the json document are defined in the file <rbeCore/jsonMember.h>

The json object that is used to setup the engine must contain the following members:
- RubberBandSteps: (Array) Contains all steps for the current Rubberband

### JSON: Step
The step must be an object having the following member:
- Step: (Integer) The ID of the step. The IDs MUST start at 1 and count up
- MayEndWithout: (Boolean) If true, then the creation of the rubberband may end on the step before the current one
- Projection: (String) The axis on which this step will project (May use: UV or W)
- Limits: (Array) Contains the limits for the axis for this step
- Points: (Array) Contains all the points created and computed at this step
- Connections: (Array) Contains all the connections that are created at this step

### JSON: Point
The point must be an object having the following member:
- ID: (Integer) The id by which the point can be referenced (The ID must be unique)
- U: (String) A formula to describe the U value of this point (See: Point-Formula)
- V: (String) As "U" but for the V axis.
- W: (String) As "W" but for the W axis.

## Point-Formula
A formula to describe the value of one of the Points axis may contain:
- Regular expressions as +, -, *, /
- The distance operator '>' that will determine the distance between two referenced points
- A reference to another point, prefix '$' + the id of the Point *
- A reference to the origin point 'Origin' *
- A reference to the current position 'Current' *

Expressions: '>' > '*' > '/' > '-' > '+'

Example:
A formula for the U axis at a point, the position will be calculated with the following formula:
Origin.U>Current.U+$1.U
In words:
The distance on the U axis between the Origin point and to that result will be added the U value of the Point with the ID 1

* All the referenced points must provide the axis of which the values will be retreived (U, V, W)

## STEP
Steps describe the sequence in which the rubberband is created. Upon creation of the Engine the invisible step 0 is activated.
When switching to the next step, all Points contained in the current (the old current) step will updated their values and make them read-only.

A Point in a step may not reference a Point of the same step. Points from one step may not reference points from a 'later' step.
