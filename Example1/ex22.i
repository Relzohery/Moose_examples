[Mesh]
   type = GeneratedMesh
   dim = 1
   nx = 100
   xmin = 0
   xmax = 10
[]

[Variables]
  [./flux]
    order = FIRST
    family = LAGRANGE
  [../]
[]

[Kernels]
  [./diff]
    type = Leakage
    variable = flux
  [../]
  [./abs]
    type = absorption
    variable = flux
  [../]
  [./source]
    type = Source
    variable = flux
  [../]
 
[]
[Materials]
  [./example]
    type = ExampleMaterial
    # Constant Diffusivity
    independent_vals = '0 5 7 10.0'
    dependent_vals_1 = '1 1 0.1 0.1'
    dependent_vals_2 = '1 1 5 5'
    dependent_vals_3 = '1 1 0.5 0.5'
  [../]
[]

[BCs]
  [./left]
    type = DirichletBC
    variable = flux
    boundary = 'left'
    value = 0
  [../]

  [./right]
    type = DirichletBC
    variable = flux
    boundary = 'right'
    value = 0
  [../]
[]

[Postprocessors]
  [./off_block]
    type = ElementalVariableValue
    variable = flux
    elementid = 100
  [../]
[]

[Executioner]
  type = Steady
  solve_type = 'PJFNK'
[]

[Outputs]
  exodus = true
  csv = true
[]
