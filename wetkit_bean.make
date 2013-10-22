; WetKit Bean Makefile

api = 2
core = 7.x

; Modules for WetKit Bean

projects[bean][version] = 1.4
projects[bean][subdir] = contrib
projects[bean][patch][1957986] = http://drupal.org/files/fix_deploy-1957986-06.patch

projects[bean_panels][version] = 1.x-dev
projects[bean_panels][subdir] = contrib
projects[bean_panels][type] = module
projects[bean_panels][download][type] = git
projects[bean_panels][download][revision] = 3a7d7f2
projects[bean_panels][download][branch] = 7.x-1.x
