# Third-Party Dependencies

本文档记录 VulkanEngine 使用的第三方依赖库及其版本信息。

## 依赖列表

### SDL (Simple DirectMedia Layer)

- **仓库**: https://github.com/libsdl-org/SDL.git
- **版本标签**: `release-2.32.10`
- **提交哈希**: `5d249570393f7a37e037abf22cd6012a4cc56a71`
- **更新日期**: 2025-10-20
- **用途**: 跨平台窗口管理、输入处理
- **备注**: SDL2 最新稳定版本

### vk-bootstrap

- **仓库**: https://github.com/charles-lunarg/vk-bootstrap.git
- **版本标签**: `v1.4.329`
- **提交哈希**: `4ecaa0fbb0eacb8dda1a7b9850df576824b47388`
- **更新日期**: 2025-10-20
- **用途**: Vulkan 初始化助手库
- **备注**: 支持最新 Vulkan-Headers

## 升级流程

### 手动升级步骤

1. 进入子模块目录并拉取最新 tags：
   ```powershell
   git -C 3rdparty/SDL fetch --tags
   git -C 3rdparty/vk-bootstrap fetch --tags
   ```

2. 查看可用版本：
   ```powershell
   git -C 3rdparty/SDL tag --sort=-v:refname | select -First 10
   git -C 3rdparty/vk-bootstrap tag --sort=-v:refname | select -First 10
   ```

3. 切换到目标版本：
   ```powershell
   git -C 3rdparty/SDL checkout <tag-name>
   git -C 3rdparty/vk-bootstrap checkout <tag-name>
   ```

4. 更新本文档中的版本信息和提交哈希

5. 在主仓库中提交子模块指针变更：
   ```powershell
   git add 3rdparty/SDL 3rdparty/vk-bootstrap DEPENDENCIES.md
   git commit -m "chore(deps): update SDL to <version>, vk-bootstrap to <version>"
   ```

6. 构建并测试：
   ```powershell
   cmake --build build --config Debug
   # 运行基础功能测试
   ```

### 验证清单

- [ ] 编译成功（Debug 和 Release）
- [ ] 窗口创建正常
- [ ] Vulkan 初始化成功
- [ ] 输入响应正常
- [ ] 无新增编译警告

## 版本策略

- **SDL**: 使用官方发布的稳定 tag（`release-x.y.z`），不跟踪分支
- **vk-bootstrap**: 使用带语义化版本的 tag（`vx.y.z`），确保与 Vulkan SDK 版本兼容
- **升级频率**: 建议每 2-3 个月检查一次更新，安全补丁及时更新

## 故障排查

如果升级后出现问题：

1. 检查子模块是否正确切换：
   ```powershell
   git submodule status
   ```

2. 清理并重新生成构建文件：
   ```powershell
   Remove-Item -Recurse -Force build
   cmake -B build -S .
   ```

3. 回退到上一个已知可工作版本：
   ```powershell
   git checkout HEAD~1 -- 3rdparty/SDL 3rdparty/vk-bootstrap
   git submodule update
   ```
