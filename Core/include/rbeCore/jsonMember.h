#pragma once

//! Type: Array
#define RBE_JSON_DOC_RubberbandSteps "RubberBandSteps"

// ##############################################################

// Step

//! Type: Integer (value > 0)
#define RBE_JSON_STEP_Step "Step"

//! Type: Boolean
#define RBE_JSON_STEP_MayEndWithout "MayEndWithout"

//! Type: String (UV, W)
#define RBE_JSON_STEP_Projection "Projection"

//! Type: Array
#define RBE_JSON_STEP_Limits "Limits"

//! Type: Array
#define RBE_JSON_STEP_Points "Points"

//! Type: Array
#define RBE_JSON_STEP_Connections "Connections"

// ##############################################################

// Point

//! Type: Integer (value > 0)
#define RBE_JSON_Point_ID "ID"

//! Type: String (Formula, see documentation)
#define RBE_JSON_Point_U "U"

//! Type: String (Formula, see documentation)
#define RBE_JSON_Point_V "V"

//! Type: String (Formula, see documentation)
#define RBE_JSON_Point_W "W"

// ##############################################################

// Connection

//! Type: String (Line, Circle)
#define RBE_JSON_CONNECTION_Type "Type"

//! (OPTIONAL) Type: Boolean
#define RBE_JSON_CONNECTION_IgnoreInHistory "IgnoreInHistory"

//! Type: String (Reference to Point)
#define RBE_JSON_CONNECTION_LINE_From "From"

//! Type: String (Reference to Point)
#define RBE_JSON_CONNECTION_LINE_To "To"

// ##############################################################

//! Used to specify a step projection for the UV axis
#define RBE_JSON_VALUE_ProjectionUV "UV"

//! Used to specify a step projection for the W axis
#define RBE_JSON_VALUE_ProjectionW "W"

//! Used to specify the connection type as a line connection
#define RBE_JSON_VALUE_ConnectionType_Line "Line"

//! Used to specify the connection type as a cicle connection
#define RBE_JSON_VALUE_ConnectionType_Circle "Circle"

//! Used to specify the connection type as a history connection
#define RBE_JSON_VALUE_ConnectionType_History "History"

// ##############################################################

//! Used to indicate a reference to a point
#define RBE_JSON_INDICATOR_Reference "$"