[Mesh]
   type = GeneratedMesh
   dim = 2
   nx = 100
   xmin = 0
   xmax = 10
   ny = 100
   ymin = 0
   ymax = 10
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
    D = 0.4
  [../]
  [./abs]
    type = Absorption
    variable = flux
    sigmaA = 0.001
  [../]
  [./source]
    type = Source
    variable = flux
    S = 1
  [../]
 [./euler]
    type = ExampleTimeDerivative
    variable = flux
    time_coefficient = 20.0
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

  [./top]
    type = DirichletBC
    variable = flux
    boundary = 'top'
    value = 0
  [../]
  
  [./bottom]
    type = DirichletBC
    variable = flux
    boundary = 'bottom'
    value = 0
  [../]
[]

[Executioner]
  type = Transient   
  solve_type = 'PJFNK'
  num_steps = 75 # Run for 75 time steps, solving the system each step.
  dt = 1 # each time step will have duration "1"
[]

[Outputs]
  execute_on = 'timestep_end'
  exodus = true
[]
