; WetKit Bean Makefile

api = 2
core = 7.x

; Modules for WetKit Bean

projects[bean][version] = 1.x-dev
projects[bean][subdir] = contrib
projects[bean][type] = module
projects[bean][download][type] = git
projects[bean][download][revision] = b4460f1
projects[bean][download][branch] = 7.x-1.x
projects[bean][patch][1957986] = http://drupal.org/files/fix_deploy-1957986-03.patch
projects[bean][patch][2060831] = http://drupal.org/files/bean_save_menu_rebuild-2060831-11.patch
projects[bean][patch][2061725] = http://drupal.org/files/uuid_revisions-2061725.patch

projects[bean_panels][version] = 1.x-dev
projects[bean_panels][subdir] = contrib
projects[bean_panels][type] = module
projects[bean_panels][download][type] = git
projects[bean_panels][download][revision] = 3a7d7f2
projects[bean_panels][download][branch] = 7.x-1.x

projects[image_link_formatter][version] = 1.x-dev
projects[image_link_formatter][subdir] = contrib
