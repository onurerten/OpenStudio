require 'fileutils'
require 'time'
require 'rbconfig'

install_dir = ARGV[0]
tar_exe = ARGV[1]
expected_ruby_version = ARGV[2]

ENV['PATH'] = "#{ENV['PATH']}#{File::PATH_SEPARATOR}#{File.dirname(tar_exe)}"

if RUBY_VERSION != expected_ruby_version
  raise "Incorrect Ruby version ${RUBY_VERSION} used, expecting #{expected_ruby_version}"
end

if /win/.match(RUBY_PLATFORM) || /mingw/.match(RUBY_PLATFORM)
  ENV['PATH'] = "#{ENV['PATH']};C:\\Program Files\\Git\\cmd"
end

if File.exists?(install_dir)
  FileUtils.rm_rf(install_dir)
end

ENV['BUNDLE_WITHOUT'] = 'test'
bundle_exe = File.join(RbConfig::CONFIG['bindir'], 'bundle')

if !File.exists?(bundle_exe)
  raise "Required bundle executable not found"
end

system("#{bundle_exe} install --without=test --path='#{install_dir}'")

FileUtils.rm_rf("#{install_dir}/ruby/2.2.0/cache")

standards_gem_dir = nil
workflow_gem_dir = nil
Dir.glob("#{install_dir}/ruby/2.2.0/bundler/gems/*").each do |f|
  if /openstudio-standards/i.match(f)
    standards_gem_dir = f
  elsif /openstudio-workflow/i.match(f)
    workflow_gem_dir = f
  end
end
Dir.glob("#{install_dir}/ruby/2.2.0/gems/*").each do |f|
  if /openstudio-standards/i.match(f)
    standards_gem_dir = f
  elsif /openstudio-workflow/i.match(f)
    workflow_gem_dir = f
  end
end

puts "standards_gem_dir = #{standards_gem_dir}"
puts "workflow_gem_dir = #{workflow_gem_dir}"

# clean up standards gem
FileUtils.rm_rf("#{standards_gem_dir}/.git")
FileUtils.rm_rf("#{standards_gem_dir}/measures")
FileUtils.rm_rf("#{standards_gem_dir}/openstudio-standards/test")
FileUtils.rm_rf("#{standards_gem_dir}/openstudio-standards/docs")
Dir.glob("#{standards_gem_dir}/data/weather/*").each do |f|
  if /CAN_/.match(f)
    FileUtils.rm_f(f)
  end
end

# clean up workflow gem
FileUtils.rm_rf("#{workflow_gem_dir}/.git")
FileUtils.rm_rf("#{workflow_gem_dir}/spec")
FileUtils.rm_rf("#{workflow_gem_dir}/test")

# copy Gemfile and Gemfile.lock
FileUtils.cp('Gemfile', "#{install_dir}/.")
FileUtils.cp('Gemfile.lock', "#{install_dir}/.")

Dir.chdir("#{install_dir}/..")

command = "\"#{tar_exe}\" -zcvf \"openstudio-gems-#{DateTime.now.strftime("%Y%m%d")}.tar.gz\" \"openstudio-gems\""
puts command
system(command)

# md5sum openstudio-gems-YYYYMMDD.tar.gz
# upload openstudio-gems-YYYYMMDD.tar.gz to s3, update openstudiocore/CMakeLists.txt