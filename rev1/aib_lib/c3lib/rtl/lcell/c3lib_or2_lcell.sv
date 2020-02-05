// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2019 Intel Corporation. 
// *****************************************************************************
// *****************************************************************************
// Copyright © 2016 Altera Corporation.                                            
// *****************************************************************************
//  Module Name :  c3lib_or2_lcell                                  
//  Date        :  Fri Apr 29 18:00:55 2016                                 
//  Description :  2-input OR gate
// *****************************************************************************

module  c3lib_or2_lcell( 

  // Functional IOs
  input  logic	in0,
  input	 logic	in1,
  output logic	out

); 

c3lib_or2_svt_2x u_c3lib_or2_svt_2x(

  .in0	( in0 ),
  .in1	( in1 ),
  .out	( out )

);

endmodule 

