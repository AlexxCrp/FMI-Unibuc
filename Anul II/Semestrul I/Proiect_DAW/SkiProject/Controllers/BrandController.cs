using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using SkiProject.Entities;
using SkiProject.Managers;
using SkiProject.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class BrandController : ControllerBase
    {
        private readonly IBrandsManager manager;

        public BrandController(IBrandsManager brandsManager)
        {
            this.manager = brandsManager;
        }

        [HttpGet]
        //[Authorize(Policy = "Admin")]
        public async Task<IActionResult> GetBrands()
        {
            var skis = manager.GetBrands();

            return Ok(skis);
        }

        [HttpGet("byId/{id}")]
        //[Authorize(Policy = "Admin")]
        public async Task<IActionResult> GetById([FromRoute] string id)
        {
            var ski = manager.GetBrandById(id);

            return Ok(ski);
        }

        [HttpPost]
        //[Authorize(Policy = "Admin")]
        public async Task<IActionResult> Create([FromBody] BrandModel brandModel)
        {
            manager.Create(brandModel);

            return Ok();
        }

        [HttpPut]
        //[Authorize(Policy = "Admin")]
        public async Task<IActionResult> Update([FromBody] BrandModel brandModel)
        {
            manager.Update(brandModel);

            return Ok();
        }

        [HttpDelete("{id}")]
        //[Authorize(Policy = "Admin")]
        public async Task<IActionResult> Delete([FromRoute] string id)
        {
            manager.Delete(id);

            return Ok();
        }
    }
}
