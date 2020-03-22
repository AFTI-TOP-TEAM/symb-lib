#!/bin/bash
string="//------------------------------------------------------------------------------
// $1
// 
// Copyright (c) 2020 Afti
// All rights reserved.
// $2
// Date:       $(date +%F)
// Author:     $(git config user.name)
//------------------------------------------------------------------------------"

echo "$string" >> $1
echo -e "#pragma once\n" >> $1